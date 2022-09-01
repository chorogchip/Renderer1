#pragma once

#include <cstdint>
#include <vector>

#include "framework.h"
#include "Texture.hpp"
#include "Vectors.h"
#include "Matrixes.h"

typedef decltype(RECT::left) win_sz;

typedef uint32_t Color;
struct Fragment {
    Color color;
    Vector3f pos;
};
typedef std::vector<Fragment> ArrayFragments;
typedef Texture<float> TextureDepthBuffer;
typedef Texture<Color> TextureColorBuffer;
