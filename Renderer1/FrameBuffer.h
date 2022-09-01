#pragma once

#include "framework.h"
#include "Types.h"

class FrameBuffer {
public:
    TextureColorBuffer buffer_color;
    TextureDepthBuffer buffer_depth;
    
    void init(HWND const &window);
    void update_w_h(win_sz client_width, win_sz client_height);
    void clear();
};

