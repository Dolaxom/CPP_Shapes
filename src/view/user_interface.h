#ifndef TOPSYSTEMS_USER_INTERFACE_H
#define TOPSYSTEMS_USER_INTERFACE_H

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "../controller/controller.h"

namespace ts {

class UserInterface {
public:
  UserInterface();
  void InitImGUI(GLFWwindow* window);
  void DrawImGUI();
  void DestroyImGUI();
  std::vector<std::shared_ptr<Figure>> Data() const noexcept;

private:
    SpawnInfo spawnInfo{};
    Controller controller{};
};

}  // namespace ts

#endif  // TOPSYSTEMS_USER_INTERFACE_H
