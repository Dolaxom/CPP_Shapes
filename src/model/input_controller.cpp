#include "input_controller.h"

void InputController::Movement(GLFWwindow* window, float& x, float& y,
                               float border) {
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
    if (x < border) x += 0.01f;
  }
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    if (x > -border) x -= 0.01f;
  }
  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
    if (y > -border) y -= 0.01f;
  }
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
    if (y < border) y += 0.01f;
  }

  glTranslatef(x, y, 0.0f);
}
