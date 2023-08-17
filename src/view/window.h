#ifndef TOPSYSTEMS_WINDOW_H
#define TOPSYSTEMS_WINDOW_H

#include "../model/components/grid.h"
#include "user_interface.h"

namespace ts {

class Window {
 public:
  Window();

  void Create();

 private:
  ts::UserInterface userInterface_;
  ts::Grid grid_;
  GLFWwindow *window_;

  float cameraX_ = 0.0f;
  float cameraY_ = 0.0f;

  void SetProjection(int width, int height) const;
  void InitFrame(GLFWwindow *window, int &width, int &height) const;
  void InitWindow();
  void InitOpenGL() const;
  void MainLoop();
  void InitAll();
  void DestroyAll();

  void Draw();
};

}  // namespace ts

#endif  // TOPSYSTEMS_WINDOW_H
