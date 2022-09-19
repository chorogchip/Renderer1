#pragma once

#include <cstdint>
#include <cstdio>
#include <vector>

#include "framework.h"
#include "Texture.hpp"
#include "Vectors.h"
#include "Matrixes.h"

typedef decltype(RECT::left) win_sz;
typedef std::vector<uint8_t> TGA_Img;
enum class ActionResult : bool { SUCCEED = true, FAILED = false, };
bool operator!(ActionResult res);

typedef uint32_t Color_u32;
typedef Vector3f Color_V3f;
typedef Vector4f Color_V4f;
typedef Vector3f Position3;
typedef Vector4f Position4;
typedef size_t Index;
typedef Vector2f UV;
typedef Vector3f Normal;
typedef Vector3f LightDiffuse;
typedef Vector3f LightSpecular;


struct Light {
    Position4 pos;
    Color_V3f color;
};
struct Camera {
    Position4 pos;

};
struct Vertex {
    Position4 pos;
    Normal normal;
    UV tex_coord;
};
struct Fragment {
    Position4 pos;
    UV tex_coord;
    LightDiffuse diffuse;
    Vector3f view_direction_fram_cam;
    Vector3f reflection_light;
};
struct ColoredPixel {
    Color_u32 color;
    Position3 pos;
};

typedef std::vector<Vertex> ArrayVertices;
typedef std::vector<Fragment> ArrayFragments;
typedef std::vector<ColoredPixel> ArrayColoredPixels;
typedef Texture<float> TextureDepthBuffer;
typedef Texture<Color_u32> TextureColorBuffer;
