#include "circle.h"

#define _USE_MATH_DEFINES
#include <cmath>

namespace ts {
Circle::Circle() { radius_ = 0.5f; }

void Circle::Draw() {
  float x, y;

  glColor3f(GetColor()[0], GetColor()[1], GetColor()[2]);
  for (double i = 0; i <= 360;) {
    glBegin(GL_TRIANGLES);

    x = GetLocation()[0] + radius_ * cos(i);
    y = GetLocation()[1] + radius_ * sin(i);
    glVertex2d(x, y);

    i += 0.5;
    x = GetLocation()[0] + radius_ * cos(i);
    y = GetLocation()[1] + radius_ * sin(i);
    glVertex2d(x, y);

    glVertex2d(GetLocation()[0], GetLocation()[1]);
    glEnd();
    i += 0.5;
  }
}

}  // namespace ts