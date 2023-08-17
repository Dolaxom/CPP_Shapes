#include "triangle.h"

namespace ts {
    Triangle::Triangle() {
        vertices_ = {-0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f};
    }

    void Triangle::Draw() {
        glBegin(GL_TRIANGLES);
        glColor3f(GetColor()[0], GetColor()[1], GetColor()[2]);
        glVertex2d(vertices_[0] + GetLocation()[0], vertices_[1] + GetLocation()[1]);
        glVertex2d(vertices_[2] + GetLocation()[0], vertices_[3] + GetLocation()[1]);
        glVertex2d(vertices_[4] + GetLocation()[0], vertices_[5] + GetLocation()[1]);
        glEnd();
    }
}  // namespace ts
