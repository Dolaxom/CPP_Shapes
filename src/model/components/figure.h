#ifndef TOPSYSTEMS_FIGURE_H
#define TOPSYSTEMS_FIGURE_H

#include <cstdint>

#include "object.h"

namespace ts {

class Figure : public Object {
 public:
  Figure();
  void SetColor(float r, float g, float b);
  float* GetColor() noexcept;
  void SetLocation(float x, float y);
  float* GetLocation() noexcept;
  void Draw() override = 0;

 private:
  float color_[3];
  float location_[2];
};

}  // namespace ts

#endif  // TOPSYSTEMS_FIGURE_H
