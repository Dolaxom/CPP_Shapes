#ifndef TOPSYSTEMS_GRID_H
#define TOPSYSTEMS_GRID_H

#include <utility>
#include <vector>

#include "object.h"

namespace ts {

class Grid : public Object {
  using vertex = std::pair<float, float>;

 public:
  Grid(float h, float w, float freq);
  void Draw() override;

 private:
  float h_;
  float w_;
  float freq_;

  const float lineStretch = 100.0f;
  std::vector<std::pair<vertex, vertex>> vertLines;
  std::vector<std::pair<vertex, vertex>> horLines;

  void FillGrid();
};

}  // namespace ts

#endif  // TOPSYSTEMS_GRID_H
