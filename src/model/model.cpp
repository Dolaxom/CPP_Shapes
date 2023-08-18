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

bool Model::CheckCollision(const float* location) const noexcept {
  for (const auto& it : objects_) {
    if (location[0] == it->GetLocation()[0] ||
        location[1] == it->GetLocation()[1]) {
      return false;
    }
  }

  return true;
}

}  // namespace ts