#include "Merger.h"

void Merger::merge(FragmentsBuffer &fragments, FrameBuffer &frame_buffer) {
    float buf_width = static_cast<float>(frame_buffer.buffer_color.get_width());
    float buf_height = static_cast<float>(frame_buffer.buffer_color.get_height());
    size_t pos_x, pos_y;

    for (auto &o : fragments.fragments)
        if (o.pos.x >= 0 && o.pos.x < buf_width && o.pos.y >= 0 && o.pos.y < buf_height &&
            frame_buffer.buffer_depth.at(pos_x = static_cast<size_t>(o.pos.x), pos_y = static_cast<size_t>(o.pos.y)) > o.pos.z)
            frame_buffer.buffer_color.at(pos_x, pos_y) = o.color;
    fragments.fragments.clear();
}