#ifndef TOPSYSTEMS_OBJECT_H
#define TOPSYSTEMS_OBJECT_H

#include <cstdint>
#include <GLFW/glfw3.h>

namespace ts {

class Object {
 public:
  uint32_t GetID() const noexcept;
  virtual void Draw() = 0;

 protected:
  Object();

 private:
  uint32_t id_;
};

}  // namespace ts

#endif  // TOPSYSTEMS_OBJECT_H
