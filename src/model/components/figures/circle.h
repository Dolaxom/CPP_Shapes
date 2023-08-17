#ifndef TOPSYSTEMS_CIRCLE_H
#define TOPSYSTEMS_CIRCLE_H

#include <vector>

#include "../figure.h"

namespace ts {

class Circle : public Figure {
 public:
  Circle();
  void Draw() override;

 private:
  float radius_;
};

}  // namespace ts

#endif  // TOPSYSTEMS_CIRCLE_H
