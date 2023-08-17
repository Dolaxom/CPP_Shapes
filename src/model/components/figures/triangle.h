#ifndef TOPSYSTEMS_TRIANGLE_H
#define TOPSYSTEMS_TRIANGLE_H

#include <vector>

#include "../figure.h"

namespace ts {

class Triangle : public Figure {
public:
    Triangle();
    void Draw() override;

private:
    std::vector<float> vertices_;
};

}  // namespace ts

#endif  // TOPSYSTEMS_TRIANGLE_H
