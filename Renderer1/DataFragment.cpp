#include "DataFragment.h"

DataFragment DataFragment::test1() {
    DataFragment fr;
    fr.fragments.emplace_back(Fragment{});
    for (float i = 50; i < 200; ++i)
        for (float j = 50; j < 200; ++j) {
            Fragment f;
            f.pos = Position4{i, j, 0.5f, 0.0f};
            f.tex_coord = UV{i, j};
            f.diffuse = LightDiffuse{0.1f, 0.1f, 0.1f};
            f.view_direction_fram_cam = Vector3f{-0.5f, -0.1f, -1.0f};
            f.reflection_light = Vector3f{0.3f, 0.3f, 0.8f};
            fr.fragments.push_back(f);
        }
    return fr;
}

/*
struct Fragment {
    Position pos;
    UV tex_coord;
    LightDiffuse diffuse;
    Vector3f view_direction_fram_cam;
    Vector3f reflection_light;
};*/