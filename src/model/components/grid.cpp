#include "grid.h"

#include <stdexcept>

namespace ts {
Grid::Grid(float h, float w, float freq) : h_{h}, w_{w}, freq_{freq} {
  if (h_ < 1 || w_ < 1 || freq <= 0.0f) {
    throw std::runtime_error(
        "Error occurred while creating an object of the Grid class - "
        "invalid input parameters.");
  }

  FillGrid();
}

void Grid::FillGrid() {
  for (float i = -h_; i <= h_; i += freq_) {
    vertLines.push_back({{i, lineStretch}, {i, -lineStretch}});
  }

  for (float i = -w_; i <= w_; i += freq_) {
    horLines.push_back({{-lineStretch, i}, {lineStretch, i}});
  }
}

void Grid::Draw() {
  glBegin(GL_LINES);
  glColor3f(0.6, 0.6, 0.6);
  for (auto it : vertLines) {
    glVertex3d(it.first.first, it.first.second, 0);
    glVertex3d(it.second.first, it.second.second, 0);
  }
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.6, 0.6, 0.6);
  for (auto it : horLines) {
    glVertex3d(it.first.first, it.first.second, 0);
    glVertex3d(it.second.first, it.second.second, 0);
  }
  glEnd();
}

}  // namespace ts