#include "Merger.h"

void Merger::merge(DataPixelColor &pixel_colors, DataFrameBuffer &frame_buffer) const {
    float buf_width = static_cast<float>(frame_buffer.buffer_color.get_width());
    float buf_height = static_cast<float>(frame_buffer.buffer_color.get_height());
    size_t pos_x, pos_y;

    for (auto &in : pixel_colors.colored_pixels) {
        in.pos.y = buf_height - in.pos.y;
        if (in.pos.x >= 0 && in.pos.x < buf_width && in.pos.y >= 0 && in.pos.y < buf_height &&
            frame_buffer.buffer_depth.at(pos_x = static_cast<size_t>(in.pos.x), pos_y = static_cast<size_t>(in.pos.y)) > in.pos.z) {
            frame_buffer.buffer_depth.at(pos_x, pos_y) = in.pos.z;
            frame_buffer.buffer_color.at(pos_x, pos_y) = in.color;
        }
    }
    pixel_colors.colored_pixels.clear();
}
