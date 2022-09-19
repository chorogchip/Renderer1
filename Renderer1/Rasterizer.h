#pragma once

#include "Types.h"
#include "Math.h"
#include "DataFragment.h"

class Rasterizer {
private:
    float win_x_;
    float win_y_;
    static Fragment gen_fragment(Fragment const &, Fragment const &, Fragment const &,
                                 float intp1, float intp2, float intp3,
                                 Vector2f pos);
public:
    void rasterize(DataFragment &, DataFragment &) const;
    void update_w_h(win_sz client_width, win_sz client_height);
};

