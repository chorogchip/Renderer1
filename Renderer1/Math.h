#pragma once
#include "Types.h"

class Math {
public:
    static float powf20(float base) {
        float res;
        base *= base;
        base *= base;
        res = base;
        base *= base;
        base *= base;
        return res * base;
    }
    static float saturate(float x) {
        return x < 1.0f ? (x > 0.0f ? x : 0.0f) : 1.0f;
    }
    static Color_u32 color_V3f_to_u32(Color_V3f &v) {
        return  static_cast<Color_u32>(v.x * 255.0f) << 16U |
                static_cast<Color_u32>(v.y * 255.0f) <<  8U |
                static_cast<Color_u32>(v.z * 255.0f)        ;
    }
};

