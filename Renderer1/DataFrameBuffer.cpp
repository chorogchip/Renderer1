#include "DataFrameBuffer.h"


void DataFrameBuffer::init(HWND const &window) {
    this->clear();
}
void DataFrameBuffer::update_w_h(win_sz client_width, win_sz client_height) {
    buffer_color.resize(client_width, client_height);
    buffer_depth.resize(client_width, client_height);
}
void DataFrameBuffer::clear() {
    buffer_color.clear(0x00ffff);
    buffer_depth.clear(1.0f);
}