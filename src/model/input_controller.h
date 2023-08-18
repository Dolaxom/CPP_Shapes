#ifndef TOPSYSTEMS_INPUT_CONTROLLER_H
#define TOPSYSTEMS_INPUT_CONTROLLER_H

#include <GLFW/glfw3.h>

namespace ts {

class InputController {
 public:
  explicit InputController(float step = 0.01f);
  void Movement(GLFWwindow* window, float& x, float& y, float border) const;

 private:
  float step_;
};

}  // namespace ts

#endif  // TOPSYSTEMS_INPUT_CONTROLLER_H
