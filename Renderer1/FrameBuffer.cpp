#include "FrameBuffer.h"


void FrameBuffer::init(HWND const &window) {
    this->clear();
}
void FrameBuffer::update_w_h(win_sz client_width, win_sz client_height) {
    buffer_color.resize(client_width, client_height);
    buffer_depth.resize(client_width, client_height);
}
void FrameBuffer::clear() {
    buffer_color.clear(0x0000ff00);
    buffer_depth.clear(1.0f);
}