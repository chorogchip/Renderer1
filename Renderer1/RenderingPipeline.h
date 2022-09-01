#pragma once
#include "framework.h"
#include "Types.h"
#include "FragmentsBuffer.h"
#include "Merger.h"
#include "FrameBuffer.h"
#include "BitmapDrawer.h"

class RenderingPipeline {
private:
    FragmentsBuffer fragments_buffer_;
    Merger merger_;
    FrameBuffer final_color_buffer_;
    BitmapDrawer drawer_;

public:
    void init(HWND const &window);
    void update_w_h(win_sz client_width, win_sz client_height);
    void draw();
};

