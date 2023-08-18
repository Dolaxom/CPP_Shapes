#include "object.h"

namespace ts {

Object::Object() : isVisible_{true} {
  static uint32_t id = 0;
  id_ = id++;
}

uint32_t Object::GetID() const noexcept { return id_; }

void Object::SetVisible(bool v) noexcept { isVisible_ = v; }

bool Object::GetVisible() const noexcept { return isVisible_; }

}  // namespace ts
