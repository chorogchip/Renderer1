#include "DataVertex.h"

DataVertex DataVertex::test1() {
    DataVertex ret;
    ret.draw_quad(Position3(-0.5f,  0.5f, 0.0f),
                  Position3(-0.5f, -0.5f, 0.0f),
                  Position3( 0.5f, -0.5f, 0.0f),
                  Position3( 0.5f,  0.5f, 0.0f),
                  UV(0.0f, 1.0f),
                  UV(0.0f, 0.0f),
                  UV(1.0f, 0.0f),
                  UV(1.0f, 1.0f));
    return ret;
}

void DataVertex::draw_triangle(Position3 p1, Position3 p2, Position3 p3,
                               UV c1, UV c2, UV c3) {
    Vector3f v1{p2 - p1};
    Vector3f v2{p3 - p2};
    Vector3f normal = v1.cross(v2);
    this->vertices.push_back(Vertex{Position4(p1, 1.0f), Normal(normal), UV(c1)});
    this->vertices.push_back(Vertex{Position4(p2, 1.0f), Normal(normal), UV(c2)});
    this->vertices.push_back(Vertex{Position4(p3, 1.0f), Normal(normal), UV(c3)});
}
void DataVertex::draw_quad(Position3 p1, Position3 p2, Position3 p3, Position3 p4,
                               UV c1, UV c2, UV c3, UV c4) {
    this->draw_triangle(p1, p2, p3, c1, c2, c3);
    this->draw_triangle(p1, p3, p4, c1, c3, c4);
}