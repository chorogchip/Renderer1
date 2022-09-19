#pragma once

#include <algorithm>

#include "Types.h"
#include "Math.h"
#include "DataFragment.h"
#include "DataPixelColor.h"

class FragmentShader {
private:
    TextureColorBuffer const *tex_diffuse_;
    TextureColorBuffer const *tex_specular_;
    Color_V3f light_color_;
public:
    void apply_shader(DataFragment &, DataPixelColor &) const;
    void set_texture_diffuse(TextureColorBuffer const &tex) {
        tex_diffuse_ = &tex;
    }
    void set_texture_specular(TextureColorBuffer const &tex) {
        tex_specular_ = &tex;
    }
    void set_light_color(Color_V3f const &color) {
        light_color_ = color;
    }
};

