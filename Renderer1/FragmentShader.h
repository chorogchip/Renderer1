#pragma once

#include <algorithm>

#include "Types.h"
#include "DataFragment.h"
#include "DataPixelColor.h"

class FragmentShader {
public:
    void apply_shader(DataFragment &,
                      TextureColorBuffer &tex_diffuse, TextureColorBuffer &tex_specular,
                      Color_V3f &light_color,
                      DataPixelColor &) const;
};

