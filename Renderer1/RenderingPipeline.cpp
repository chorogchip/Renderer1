#include "RenderingPipeline.h"

void RenderingPipeline::init(HWND const &window) {
    final_color_buffer_.init(window);
    drawer_.init(window);
}
void RenderingPipeline::update_w_h(win_sz client_width, win_sz client_height) {
    final_color_buffer_.update_w_h(client_width, client_height);
    drawer_.update_w_h(client_width, client_height);
}
void RenderingPipeline::draw() {
    fragments_buffer_ = FragmentsBuffer::test1();
    final_color_buffer_.clear();
    merger_.merge(fragments_buffer_, final_color_buffer_);
    drawer_.draw(final_color_buffer_);
}
