#pragma once

#include <algorithm>

#include "Types.h"
#include "Math.h"
#include "DataVertex.h"
#include "DataFragment.h"

class VertexShader {
private:
    Matrix4x4f mat_world_;
    Matrix4x4f mat_view_;
    Matrix4x4f mat_proj_;
    Position4 pos_world_light_;
    Position4 pos_world_cam_;
public:
    void apply_shader(DataVertex &, DataFragment &) const;
    void set_matrix_world(Matrix4x4f const &mat) {
        mat_world_ = mat;
    }
    void set_matrix_view(Matrix4x4f const &mat) {
        mat_view_ = mat;
    }
    void set_matrix_projection(Matrix4x4f const &mat) {
        mat_proj_ = mat;
    }
    void set_pos_world_light(Position4 const &pos) {
        pos_world_light_ = pos;
    }
    void set_pos_world_cam(Position4 const &pos) {
        pos_world_cam_ = pos;
    }
};

