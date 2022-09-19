#pragma once

#include "framework.h"
#include "Types.h"

class DataVertex {
public:
    ArrayVertices vertices;
    static DataVertex test1();
    static DataVertex test2();
private:
    void draw_triangle(Position3, Position3, Position3, UV, UV, UV);
    void draw_quad(Position3, Position3, Position3, Position3, UV, UV, UV, UV);
    void draw_cube(Position3 pos, float sz, float uv_x_min, float uv_x_max, float uv_y_min, float uv_y_max);
};

