#ifndef TOPSYSTEMS_CONTROLLER_H
#define TOPSYSTEMS_CONTROLLER_H

#include <string>

#include "../model/model.h"

namespace ts {
struct SpawnInfo {
  float location[2];
  float color[3];
  std::string type;
};

class Controller {
 public:
  void Create(const SpawnInfo& spawnInfo);
  std::vector<std::shared_ptr<Figure>> GetDrawData() const noexcept;

 private:
  Model model;
};

}  // namespace ts

#endif  // TOPSYSTEMS_CONTROLLER_H
