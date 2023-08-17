#include "figure.h"

namespace ts {
Figure::Figure() : color_{0.0f, 0.0f, 0.0f}, location_{0.0f, 0.0f} {}

void Figure::SetColor(float r, float g, float b) {
  color_[0] = r;
  color_[1] = g;
  color_[2] = b;
}

float* Figure::GetColor() noexcept { return color_; }

void Figure::SetLocation(float x, float y) {
  location_[0] = x;
  location_[1] = y;
}

float* Figure::GetLocation() noexcept { return location_; }
}  // namespace ts
