#ifndef TOPSYSTEMS_INPUT_CONTROLLER_H
#define TOPSYSTEMS_INPUT_CONTROLLER_H

#include <GLFW/glfw3.h>

class InputController {
 public:
  static void Movement(GLFWwindow* window, float& x, float& y, float border);
};

#endif  // TOPSYSTEMS_INPUT_CONTROLLER_H
