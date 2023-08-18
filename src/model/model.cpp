#include "model.h"

namespace ts {
void Model::AddObject(const std::shared_ptr<Figure>& object) {
  //  SetObjectLocation(object);
  objects_.push_back(object);
}

void Model::SetObjectLocation(const std::shared_ptr<Figure>& object) {
  object->SetLocation((float)objects_.size(), 0);
}

std::vector<std::shared_ptr<Figure>> Model::GetObjects() const noexcept {
  return objects_;
}

void Model::Clamp(float& value, float min, float max) {
  if (value > max) value = max;
  if (value < min) value = min;
}

}  // namespace ts