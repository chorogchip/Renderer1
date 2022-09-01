#pragma once

#include "Types.h"
#include "FragmentsBuffer.h"
#include "FrameBuffer.h"

class Merger {
public:
    void merge(FragmentsBuffer &fragments, FrameBuffer &frame_buffer);
};

