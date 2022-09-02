#pragma once
#include <vector>
#include <cassert>
#include "framework.h"
#include "tga-main/tga.h"
#include "Types.h"

#include "DataFragment.h"
#include "FragmentShader.h"
#include "DataPixelColor.h"
#include "Merger.h"
#include "DataFrameBuffer.h"
#include "BitmapDrawer.h"

class RenderingPipeline {
private:
    DataFragment fragments_;
    FragmentShader fragment_shader_;
    DataPixelColor colored_fragments_;
    Merger merger_;
    DataFrameBuffer final_color_buffer_;
    BitmapDrawer drawer_;

    TextureColorBuffer texture_diffuse_;
    TextureColorBuffer texture_specular_;

    static ActionResult load_TGA_texture(TextureColorBuffer &, char const *file_name);
public:
    ActionResult init(HWND const &window);
    void update_w_h(win_sz client_width, win_sz client_height);
    void draw();
};

