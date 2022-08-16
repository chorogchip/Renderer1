#pragma once
#include "framework.h"

#include "BitmapDrawer.h"

class RenderingPipeline {
private:
    BitmapDrawer drawer_;
public:
    void init(HWND window);
    void update();
    void draw();
    void update_w_h(HWND window);
};

