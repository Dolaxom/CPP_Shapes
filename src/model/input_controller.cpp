#include "input_controller.h"

namespace ts {

InputController::InputController(float step) : step_{step} {}

void InputController::Movement(GLFWwindow *window, float &x, float &y,
                               float border) const {
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
    if (x < border) x += step_;
  }
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    if (x > -border) x -= step_;
  }
  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
    if (y > -border) y -= step_;
  }
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
    if (y < border) y += step_;
  }

  glTranslatef(x, y, 0.0f);
}

}  // namespace ts