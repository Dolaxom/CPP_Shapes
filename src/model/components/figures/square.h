#ifndef TOPSYSTEMS_SQUARE_H
#define TOPSYSTEMS_SQUARE_H

#include <vector>

#include "../figure.h"

namespace ts {

class Square : public Figure {
 public:
  Square();
  void Draw() override;

 private:
  std::vector<float> vertices_;
};

}  // namespace ts

#endif  // TOPSYSTEMS_SQUARE_H
