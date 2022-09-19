#include "VertexShader.h"

void VertexShader::apply_shader(DataVertex &vertices_in, DataFragment &fragments_out) const {
    for (auto &in : vertices_in.vertices) {
        Fragment out;
        out.pos = mat_world_ * in.pos;

        Vector3f light_dir{out.pos - pos_world_light_};
        light_dir.normalize();

        Vector3f view_dir{out.pos - pos_world_cam_};
        view_dir.normalize();
        out.view_direction_fram_cam = view_dir;

        out.pos = mat_view_ * out.pos;
        out.pos = mat_proj_ * out.pos;

        Vector3f world_noraml{Matrix3x3f{mat_world_} * in.normal};
        world_noraml.normalize();
        
        float dif_lit{(-light_dir).inner(world_noraml)};
        out.diffuse = Vector3f{ dif_lit, dif_lit, dif_lit };
        out.reflection_light = light_dir.reflect(world_noraml);

        out.tex_coord = in.tex_coord;

        fragments_out.fragments.push_back(out);
    }
    vertices_in.vertices.clear();
}

/*
struct Vertex {
    Position4 pos;
    Vector3f normal;
    UV tex_coord;
};
struct VertexShaded {
    Position4 pos;
    UV tex_coord;
    LightDiffuse diffuse;
    Vector3f view_direction_fram_cam;
    Vector3f reflection_light;
};
*/