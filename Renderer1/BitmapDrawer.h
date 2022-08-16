#pragma once
#include <stdint.h>

#include "framework.h"
#include "Texture.hpp"

class BitmapDrawer {
private:
    Texture<uint32_t> tex_;
    BITMAPINFO info_;
    HDC device_context_;
public:
    void init(HWND window);
    void update_w_h(HWND window);
    void draw();
};

