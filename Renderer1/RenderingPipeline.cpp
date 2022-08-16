#include "RenderingPipeline.h"

void RenderingPipeline::init(HWND window) {
    drawer_.init(window);
}
void RenderingPipeline::update() {

}
void RenderingPipeline::draw() {
    drawer_.draw();
}
void RenderingPipeline::update_w_h(HWND window) {
    drawer_.update_w_h(window);
}