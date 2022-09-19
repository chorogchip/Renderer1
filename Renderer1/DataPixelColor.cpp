#include "DataPixelColor.h"

DataPixelColor DataPixelColor::test1() {
    DataPixelColor fb;
    for (float i = 10; i < 100; i += 1) for (float j = 50; j < 300; j += 1)
        fb.colored_pixels.emplace_back(ColoredPixel{Color_u32{0x0000ff}, Position3{i, j, 0.1f}});
    for (float i = 20; i < 150; i += 1) for (float j = 30; j < 200; j += 1)
        fb.colored_pixels.emplace_back(ColoredPixel{Color_u32{0xff0000}, Position3{i, j, 0.2f}});
    return fb;
}