#include "FragmentShader.h"
#include <algorithm>

void FragmentShader::apply_shader(DataFragment &fragments_in, DataPixelColor &pixel) const {
    for (auto &in : fragments_in.fragments) {
        Color_V3f albedo = Color_V3f{tex_diffuse_->at(in.tex_coord.x, in.tex_coord.y)};
        Vector3f diffuse = albedo * light_color_ * in.diffuse.saturate();
        Vector3f reflection = in.reflection_light.get_normalize();
        Vector3f view_dir = in.view_direction_fram_cam.get_normalize();
        Vector3f specular{};
        if (diffuse.x > 0.0f) {
            float spec_lit{Math::saturate(reflection.inner(-view_dir))};
            spec_lit = Math::powf20(spec_lit);
            Color_V3f specular_intensity{tex_specular_->at(in.tex_coord.x, in.tex_coord.y)};
            specular = specular_intensity * light_color_ * spec_lit;
        }
        Color_V3f ambient{albedo * 0.1f};
        Color_V3f color_res_V3f = ambient + diffuse + specular;
        color_res_V3f.saturate();
        Color_u32 color_res_u32{Math::color_V3f_to_u32(color_res_V3f)};
        pixel.colored_pixels.emplace_back(ColoredPixel{Color_u32{ color_res_u32 }, Position3{ in.pos }});
    }
    fragments_in.fragments.clear();
}