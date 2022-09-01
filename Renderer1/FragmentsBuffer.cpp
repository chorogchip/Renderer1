#include "FragmentsBuffer.h"

FragmentsBuffer FragmentsBuffer::test1() {
    FragmentsBuffer fb;
    for (float i = 10; i < 100; i += 1) for (float j = 50; j < 300; j += 1)
        fb.fragments.push_back(Fragment{Color{0x00f00000}, Vector3f{i, j, 0.1f}});
    for (float i = 20; i < 150; i += 1) for (float j = 30; j < 200; j += 1)
        fb.fragments.push_back(Fragment{Color{0x00ffff00}, Vector3f{i, j, 0.2f}});
    return fb;
}