#include "Rasterizer.h"
#include <cassert>

void Rasterizer::rasterize(DataFragment &fragments_in, DataFragment &fragments_out) const {
    int sz{static_cast<int>(fragments_in.fragments.size())};
    if (sz % 3) sz -= 3;
    for (int i = 0; i < sz; i += 3) {
        auto *in1{&fragments_in.fragments[i]};
        auto *in2{&fragments_in.fragments[i+1]};
        auto *in3{&fragments_in.fragments[i+2]};
        
        // clipping
        // no

        // perspective division
        in1->pos /= in1->pos.w;
        in2->pos /= in2->pos.w;
        in3->pos /= in3->pos.w;

        // cull face
        Vector3f v1{in2->pos - in1->pos};
        Vector3f v2{in3->pos - in1->pos};
        float determinant{v1.x * v2.y - v1.y * v2.x};
        if (determinant < 0.0f)
            continue;

        // viewport transform
        Matrix4x4f mat_viewport = Matrix4x4f::get_viewport(win_x_, win_y_, 0.0f, 0.0f, 0.0f, 1.0f);
        in1->pos = mat_viewport * in1->pos;
        in2->pos = mat_viewport * in2->pos;
        in3->pos = mat_viewport * in3->pos;

        // scan conversion
        if (in1->pos.y < in2->pos.y)
            std::swap(in1, in2);
        if (in1->pos.y < in3->pos.y)
            std::swap(in1, in3);
        if (in2->pos.y > in3->pos.y)
            std::swap(in2, in3);
        Vector2f p1{in1->pos - in2->pos};
        Vector2f p2{in3->pos - in2->pos};
        Vector2f p3{in1->pos - in3->pos};
        determinant = p1.x * p2.y - p2.x * p1.y;
        if (determinant > 0) {
            // left side
            if (p2.y >= 1.0f) for (float f = in2->pos.y; f <  in3->pos.y; f += 1.0f) {
                float ff{f - in2->pos.y};
                float st{ff * p2.x / p2.y + in2->pos.x};
                float fn{ff * p1.x / p1.y + in2->pos.x};
                float st_intp{ff / p2.y};
                float fn_intp{ff / p1.y};
                float len_f2{fn - st};
                if (len_f2 >= 1.0f) for (float f2 = st; f2 <= fn; f2 += 1.0f) {
                    float f2_intp{(f2 - st) / len_f2};
                    fragments_out.fragments.push_back(gen_fragment(*in1, *in2, *in3,
                                                                    f2_intp * (1.0f - st_intp),
                                                                   f2_intp * st_intp + (1.0f - f2_intp) * fn_intp,
                                                                   (1.0f - f2_intp) * (1.0f - fn_intp),
                                                                   Vector2f{f2, f}));
                }
            }
            if (p3.y >= 1.0f) for (float f = in3->pos.y; f <= in1->pos.y; f += 1.0f) {
                float ff{f - in2->pos.y};
                float ff2{f - in3->pos.y};
                float st{ff2 * p3.x / p3.y + in3->pos.x};
                float fn{ff * p1.x / p1.y + in2->pos.x};
                float st_intp{ff2 / p3.y};
                float fn_intp{ff / p1.y};
                float len_f2{fn - st};
                if (len_f2 >= 1.0f) for (float f2 = st; f2 <= fn; f2 += 1.0f) {
                    float f2_intp{(f2 - st) / len_f2};
                    fragments_out.fragments.push_back(gen_fragment(*in1, *in2, *in3,
                                                                   f2_intp * (1.0f - st_intp) + (1.0f - f2_intp) * (1.0f - fn_intp),
                                                                   f2_intp * st_intp,
                                                                   (1.0f - f2_intp) * fn_intp,
                                                                   Vector2f{f2, f}));
                }
            }
        } else {
            // right side
            if (p2.y >= 1.0f) for (float f = in2->pos.y; f <  in3->pos.y; f += 1.0f) {
                float ff{f - in2->pos.y};
                float fn{ff * p2.x / p2.y + in2->pos.x};
                float st{ff * p1.x / p1.y + in2->pos.x};
                float fn_intp{ff / p2.y};
                float st_intp{ff / p1.y};
                float len_f2{fn - st};
                if (len_f2 >= 1.0f) for (float f2 = st; f2 <= fn; f2 += 1.0f) {
                    float f2_intp{(f2 - st) / len_f2};
                    fragments_out.fragments.push_back(gen_fragment(*in1, *in2, *in3,
                                                                   f2_intp * (1.0f - st_intp),
                                                                   f2_intp * st_intp + (1.0f - f2_intp) * fn_intp,
                                                                   (1.0f - f2_intp) * (1.0f - fn_intp),
                                                                   Vector2f{f2, f}));
                }
            }
            if (p3.y >= 1.0f) for (float f = in3->pos.y; f <= in1->pos.y; f += 1.0f) {
                float ff{f - in2->pos.y};
                float ff2{f - in3->pos.y};
                float fn{ff2 * p3.x / p3.y + in3->pos.x};
                float st{ff * p1.x / p1.y + in2->pos.x};
                float fn_intp{ff2 / p3.y};
                float st_intp{ff / p1.y};
                float len_f2{fn - st};
                if (len_f2 >= 1.0f) for (float f2 = st; f2 <= fn; f2 += 1.0f) {
                    float f2_intp{(f2 - st) / len_f2};
                    fragments_out.fragments.push_back(gen_fragment(*in1, *in2, *in3,
                                                                   f2_intp * (1.0f - st_intp) + (1.0f - f2_intp) * (1.0f - fn_intp),
                                                                   f2_intp * st_intp,
                                                                   (1.0f - f2_intp) * fn_intp,
                                                                   Vector2f{f2, f}));
                }
            }
        }
    }
    fragments_in.fragments.clear();
}

void Rasterizer::update_w_h(win_sz client_width, win_sz client_height) {
    win_x_ = static_cast<float>(client_width);
    win_y_ = static_cast<float>(client_height);
}

Fragment Rasterizer::gen_fragment(Fragment const &f1, Fragment const &f2, Fragment const &f3,
                                  float intp1, float intp2, float intp3,
                                  Vector2f pos) {
#define INTP(x) (f1.x * intp1 + f2.x * intp2 + f3.x * intp3) 
    Fragment ret;
    float sum{intp1 + intp2 + intp3};
    intp1 /= sum;
    intp2 /= sum;
    intp3 /= sum;
    ret.diffuse = INTP(diffuse);
    ret.pos = Position4{pos.x, pos.y, INTP(pos.z), 1.0f};
    ret.reflection_light = INTP(reflection_light);
    ret.tex_coord = INTP(tex_coord);
    ret.view_direction_fram_cam = INTP(view_direction_fram_cam);

    assert(ret.tex_coord.x >= 0.0f);
    assert(ret.tex_coord.x <=  1.0f);
    assert(ret.tex_coord.y >= 0.0f);
    assert(ret.tex_coord.y <=  1.0f);

    return ret;
#undef INTP
}