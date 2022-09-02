#include "BitmapDrawer.h"

void BitmapDrawer::init(HWND const &window) {
    device_context_ = GetDC(window);
    info_.bmiHeader.biSize = sizeof(info_.bmiHeader);
    info_.bmiHeader.biPlanes = 1;
    info_.bmiHeader.biBitCount = 32;
    info_.bmiHeader.biCompression = BI_RGB;
}
void BitmapDrawer::update_w_h(win_sz client_width, win_sz client_height) {
    info_.bmiHeader.biWidth = static_cast<decltype(info_.bmiHeader.biWidth)>(client_width);
    info_.bmiHeader.biHeight = -static_cast<decltype(info_.bmiHeader.biHeight)>(client_height);
}
void BitmapDrawer::draw(DataFrameBuffer const &tex) {
   this->draw(tex.buffer_color);
}
void BitmapDrawer::draw(TextureColorBuffer const &buf) {
    this->update_w_h(static_cast<win_sz>(buf.get_width()), static_cast<win_sz>(buf.get_height()));
    StretchDIBits(device_context_,
                  0, 0, static_cast<int>(buf.get_width()), static_cast<int>(buf.get_height()),
                  0, 0, static_cast<int>(buf.get_width()), static_cast<int>(buf.get_height()),
                  buf.get_data(), &info_, DIB_RGB_COLORS, SRCCOPY);
}