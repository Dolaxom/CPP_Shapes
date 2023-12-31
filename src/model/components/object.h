#ifndef TOPSYSTEMS_OBJECT_H
#define TOPSYSTEMS_OBJECT_H

#include <GLFW/glfw3.h>

#include <cstdint>

namespace ts {

class Object {
 public:
  uint32_t GetID() const noexcept;
  virtual void Draw() = 0;

  void SetVisible(bool v) noexcept;
  bool GetVisible() const noexcept;

 protected:
  Object();

 private:
  uint32_t id_;
  bool isVisible_;
};

}  // namespace ts

#endif  // TOPSYSTEMS_OBJECT_H
