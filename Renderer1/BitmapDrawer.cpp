#include "BitmapDrawer.h"

void BitmapDrawer::init(HWND const &window) {
    device_context_ = GetDC(window);
    /*
    RECT ClientRect;
    GetClientRect(window, &ClientRect);
    auto ClientWidth = ClientRect.right - ClientRect.left;
    auto ClientHeight = ClientRect.bottom - ClientRect.top;
    */
    info_.bmiHeader.biSize = sizeof(info_.bmiHeader);
    //info_.bmiHeader.biWidth = static_cast<decltype(info_.bmiHeader.biWidth)>(ClientWidth);
    //info_.bmiHeader.biHeight = -static_cast<decltype(info_.bmiHeader.biHeight)>(ClientHeight);
    info_.bmiHeader.biPlanes = 1;
    info_.bmiHeader.biBitCount = 32;
    info_.bmiHeader.biCompression = BI_RGB;
}
void BitmapDrawer::update_w_h(win_sz client_width, win_sz client_height) {
    info_.bmiHeader.biWidth = static_cast<decltype(info_.bmiHeader.biWidth)>(client_width);
    info_.bmiHeader.biHeight = -static_cast<decltype(info_.bmiHeader.biHeight)>(client_height);
}
void BitmapDrawer::draw(FrameBuffer const &tex) {
    StretchDIBits(device_context_,
                  0, 0, static_cast<int>(tex.buffer_color.get_width()), static_cast<int>(tex.buffer_color.get_height()),
                  0, 0, static_cast<int>(tex.buffer_color.get_width()), static_cast<int>(tex.buffer_color.get_height()),
                  tex.buffer_color.get_data(), &info_, DIB_RGB_COLORS, SRCCOPY);
}