#pragma once

#include "Types.h"
#include "DataPixelColor.h"
#include "DataFrameBuffer.h"

class Merger {
public:
    void merge(DataPixelColor &, DataFrameBuffer &) const;
};

