#pragma once

#include "framework.h"
#include "Types.h"

class DataVertex {
public:
    ArrayVertices vertices;
    static DataVertex test1();
private:
    void draw_triangle(Position3, Position3, Position3, UV, UV, UV);
    void draw_quad(Position3, Position3, Position3, Position3, UV, UV, UV, UV);
};

