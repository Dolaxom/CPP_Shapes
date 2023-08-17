#ifndef TOPSYSTEMS_MODEL_H
#define TOPSYSTEMS_MODEL_H

#include <memory>
#include <unordered_map>
#include <vector>

#include "components/figure.h"

namespace ts {
class Model {
 public:
  Model() = default;
  void AddObject(const std::shared_ptr<Figure>& object);
  std::vector<std::shared_ptr<Figure>> GetObjects() const noexcept;

  bool CheckCollision(const float* location) const noexcept;

 private:
  std::vector<std::shared_ptr<Figure>> objects_;

  void SetObjectLocation(const std::shared_ptr<Figure>& object);
};

}  // namespace ts

#endif  // TOPSYSTEMS_MODEL_H
