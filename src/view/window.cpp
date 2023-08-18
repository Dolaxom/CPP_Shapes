#include "window.h"

#include <stdexcept>

namespace ts {

Window::Window()
    : grid_{20, 20, 0.25f}, window_{nullptr}, inputController_{0.01f} {}

void Window::Create() {
  InitAll();
  MainLoop();
  DestroyAll();
}

void Window::InitAll() {
  if (!glfwInit()) {
    throw std::runtime_error("GLFW can`t init!");
  }

  InitWindow();
  userInterface_.InitImGUI(window_);
  InitOpenGL();
}

void Window::MainLoop() {
  while (!glfwWindowShouldClose(window_)) {
    int width, height;
    InitFrame(window_, width, height);

    SetProjection(width, height);

    inputController_.Movement(window_, cameraX_, cameraY_, 5.0f);

    Draw();
  }
}

void Window::DestroyAll() {
  userInterface_.DestroyImGUI();
  glfwDestroyWindow(window_);
  glfwTerminate();
}

void Window::Draw() {
  grid_.Draw();
  for (const auto &it : userInterface_.Data()) {
    if (it->GetVisible()) it->Draw();
  }
  userInterface_.DrawImGUI();

  glfwSwapBuffers(window_);
  glfwPollEvents();
}

void Window::InitOpenGL() const {
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
  glEnable(GL_LINE_SMOOTH);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glEnable(GL_POLYGON_SMOOTH);
  glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Window::InitWindow() {
  window_ = glfwCreateWindow(1024, 720, "TopSystems Task", nullptr, nullptr);
  glfwMakeContextCurrent(window_);
  if (!window_) {
    glfwTerminate();
    throw std::runtime_error("Window can`t init!");
  }
}

void Window::InitFrame(GLFWwindow *window, int &width, int &height) const {
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.1, 0.1, 0.1, 1.0);
}

void Window::SetProjection(int width, int height) const {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (width >= height) {
    glOrtho(-2 * ((float)width / (float)height),
            2 * ((float)width / (float)height), -2, 2, 0, 100);
  } else {
    glOrtho(-2, 2, -2 * ((float)height / (float)width),
            2 * ((float)height / (float)width), 0, 100);
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

}  // namespace ts