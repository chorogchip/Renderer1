#include "DataFragment.h"

DataFragment DataFragment::test1() {
    DataFragment fr;
    fr.fragments.emplace_back(Fragment{});
    return fr;
}


struct Fragment {
    Position pos;
    UV tex_coord;
    LightDiffuse diffuse;
    Vector3f view_direction_fram_cam;
    Vector3f reflection_light;
};