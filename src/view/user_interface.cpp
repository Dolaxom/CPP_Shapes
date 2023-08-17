#include "user_interface.h"

namespace ts {

UserInterface::UserInterface() : spawnInfo{{0.0f, 0.0f}, {0.8f, 0.8f, 1.0f}} {}

void UserInterface::InitImGUI(GLFWwindow* window) {
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  ImGui::StyleColorsDark();
  io.Fonts->AddFontDefault();
  io.Fonts->Build();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");
}

void UserInterface::DrawImGUI() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::Begin("Creating Shapes");

  ImGui::PushItemWidth(75.0f);
  ImGui::Text("Set color:");
  ImGui::InputFloat("##r", &spawnInfo.color[0]);
  ImGui::SameLine();
  ImGui::InputFloat("##g", &spawnInfo.color[1]);
  ImGui::SameLine();
  ImGui::InputFloat("##b", &spawnInfo.color[2]);
  ImGui::PopItemWidth();

  ImGui::PushItemWidth(75.0f);
  ImGui::NewLine();
  ImGui::Text("Set location:");
  ImGui::InputFloat("##LocX", &spawnInfo.location[0]);
  ImGui::SameLine();
  ImGui::InputFloat("##LocY", &spawnInfo.location[1]);
  ImGui::PopItemWidth();

  ImGui::NewLine();

  ImGui::Text("Select shape:");

  const char* items_[] = {"Square", "Triangle", "Circle"};
  static const char* currentItem = items_[0];
  spawnInfo.type = currentItem;
  ImGui::PushItemWidth(125.0f);
  if (ImGui::BeginCombo("##combo", currentItem)) {
    for (int n = 0; n < IM_ARRAYSIZE(items_); n++) {
      bool isSelected = (currentItem == items_[n]);
      if (ImGui::Selectable(items_[n], isSelected)) {
        currentItem = items_[n];
      }
      if (isSelected) {
        ImGui::SetItemDefaultFocus();
      }
    }

    ImGui::EndCombo();
  }
  ImGui::PopItemWidth();

  ImGui::NewLine();
  if (ImGui::Button("Create shape!")) {
    controller.Create(spawnInfo);
  }

  ImGui::Text("\n*No restrictions on drawing shapes\nin the same place.");

  ImGui::End();

  // Отрисовываем GUI
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UserInterface::DestroyImGUI() {
  ImGui_ImplGlfw_Shutdown();
  ImGui_ImplOpenGL3_Shutdown();
  ImGui::DestroyContext();
}

std::vector<std::shared_ptr<Figure>> UserInterface::Data() const noexcept {
  return controller.GetDrawData();
}

}  // namespace ts