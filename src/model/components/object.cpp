#include "object.h"

namespace ts {
Object::Object() {
  static uint32_t id = 0;
  id_ = id++;
}

uint32_t Object::GetID() const noexcept { return id_; }
}  // namespace ts