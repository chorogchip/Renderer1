#pragma once

#include "framework.h"
#include "Types.h"
#include "DataFrameBuffer.h"

class BitmapDrawer {
private:
    BITMAPINFO info_;
    HDC device_context_;
public:
    void init(HWND const &window);
    void update_w_h(win_sz client_width, win_sz client_height);
    void draw(DataFrameBuffer const &);
    void draw(TextureColorBuffer const &);
};

