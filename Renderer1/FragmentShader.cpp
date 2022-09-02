#include "FragmentShader.h"
#include <algorithm>

void FragmentShader::apply_shader(DataFragment &fragment,
                                  TextureColorBuffer &tex_diffuse, TextureColorBuffer &tex_specular,
                                  Color_V3f &light_color,
                                  DataPixelColor &pixel) const {
    for (auto &o : fragment.fragments) {
        Color_V3f albedo{tex_diffuse.at(static_cast<size_t>(o.tex_coord.x), static_cast<size_t>(o.tex_coord.y))};
        Vector3f diffuse = albedo * light_color * o.diffuse.saturate();
        Vector3f reflection = o.reflection_light.get_normalize();
        Vector3f view_dir = o.view_direction_fram_cam.get_normalize();
        Vector3f specular{};
        if (diffuse.x > 0.0f) {
            float spec_lit{std::clamp(reflection.inner(-view_dir), 0.0f, 1.0f)};
            spec_lit = std::powf(spec_lit, 20.0f);
            Color_V3f specular_intensity{tex_specular.at(static_cast<size_t>(o.tex_coord.x), static_cast<size_t>(o.tex_coord.y))};
            specular = specular_intensity * light_color * spec_lit;
        }
        Color_V3f ambient{albedo * 0.1f};
        Color_V3f color_res_V3f = ambient + diffuse + specular;
        color_res_V3f.saturate();
        Color_u32 color_res_u32 =   static_cast<Color_u32>(color_res_V3f.x * 255.0f) << 24U |
                                    static_cast<Color_u32>(color_res_V3f.y * 255.0f) << 16U |
                                    static_cast<Color_u32>(color_res_V3f.z * 255.0f) <<  8U | 1U;
        pixel.colored_pixels.emplace_back(ColoredPixel{Color_u32{ color_res_u32 }, Position{ o.pos }});
    }
}