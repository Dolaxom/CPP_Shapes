#include "square.h"

namespace ts {
Square::Square() {
  vertices_ = {-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f};
}

void Square::Draw() {
  glBegin(GL_QUADS);
  glColor3f(GetColor()[0], GetColor()[1], GetColor()[2]);
  glVertex2d(vertices_[0] + GetLocation()[0], vertices_[1] + GetLocation()[1]);
  glVertex2d(vertices_[2] + GetLocation()[0], vertices_[3] + GetLocation()[1]);
  glVertex2d(vertices_[4] + GetLocation()[0], vertices_[5] + GetLocation()[1]);
  glVertex2d(vertices_[6] + GetLocation()[0], vertices_[7] + GetLocation()[1]);
  glEnd();
}
}  // namespace ts