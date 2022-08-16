#include "BitmapDrawer.h"

void BitmapDrawer::init(HWND window) {
    this->update_w_h(window);
    device_context_ = GetDC(window);

    info_.bmiHeader.biSize = sizeof(info_.bmiHeader);
    info_.bmiHeader.biWidth = static_cast<decltype(info_.bmiHeader.biWidth)>(tex_.get_width());
    info_.bmiHeader.biHeight = -static_cast<decltype(info_.bmiHeader.biHeight)>(tex_.get_height());
    info_.bmiHeader.biPlanes = 1;
    info_.bmiHeader.biBitCount = 32;
    info_.bmiHeader.biCompression = BI_RGB;

    tex_.clear(0xffffff00);
}
void BitmapDrawer::update_w_h(HWND window) {
    RECT ClientRect;
    GetClientRect(window, &ClientRect);
    auto ClientWidth = ClientRect.right - ClientRect.left;
    auto ClientHeight = ClientRect.bottom - ClientRect.top;
    tex_.resize(ClientWidth, ClientHeight);

    info_.bmiHeader.biWidth = static_cast<decltype(info_.bmiHeader.biWidth)>(tex_.get_width());
    info_.bmiHeader.biHeight = -static_cast<decltype(info_.bmiHeader.biHeight)>(tex_.get_height());
}
void BitmapDrawer::draw() {
    StretchDIBits(device_context_,
                  0, 0, static_cast<int>(tex_.get_width()), static_cast<int>(tex_.get_height()),
                  0, 0, static_cast<int>(tex_.get_width()), static_cast<int>(tex_.get_height()),
                  tex_.get_data(), &info_, DIB_RGB_COLORS, SRCCOPY);
}