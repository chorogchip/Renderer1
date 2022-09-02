#include "Vectors.h"

Vector2f::Vector2f(float x, float y):
    x{x},
    y{y}
{}
Vector2f const Vector2f::operator-() const {
    return Vector2f{ -x, -y };
}
Vector2f const Vector2f::operator+(Vector2f const &v) const {
    return Vector2f{ x + v.x, y + v.y };
}
Vector2f const Vector2f::operator-(Vector2f const &v) const {
    return Vector2f{ x - v.x, y - v.y };
}
Vector2f const Vector2f::operator*(Vector2f const &v) const {
    return Vector2f{ x * v.x, y * v.y };
}
Vector2f const Vector2f::operator*(float f) const {
    return Vector2f{ x * f, y * f };
}
Vector2f const Vector2f::operator/(float f) const {
    return Vector2f{ x / f, y / f };
}
Vector2f &Vector2f::operator+=(Vector2f const &v) {
    x += v.x;
    y += v.y;
    return *this;
}
Vector2f &Vector2f::operator-=(Vector2f const &v) {
    x -= v.x;
    y -= v.y;
    return *this;
}
Vector2f &Vector2f::operator*=(Vector2f const &v) {
    x *= v.x;
    y *= v.y;
    return *this;
}
Vector2f &Vector2f::operator*=(float f) {
    x *= f;
    y *= f;
    return *this;
}
Vector2f &Vector2f::operator/=(float f) {
    x /= f;
    y /= f;
    return *this;
}
float Vector2f::length() const {
    return sqrtf(x*x + y*y);
}
Vector2f const Vector2f::get_normalize() const {
    return this->operator/(this->length());
}
Vector2f &Vector2f::normalize() {
    this->operator/=(this->length());
    return *this;
}
Vector2f &Vector2f::saturate() {
    x = x < 1.0f ? (x > 0.0f ? x : 0.0f) : 1.0f;
    y = y < 1.0f ? (y > 0.0f ? y : 0.0f) : 1.0f;
    return *this;
}
Vector2f &Vector2f::clamp(float min, float max) {
    x = x < max ? (x > min ? x : min) : max;
    y = y < max ? (y > min ? y : min) : max;
    return *this;
}

Vector2f const Vector2f::get_unit_x() {
    return Vector2f{1.0f, 0.0f};
}
Vector2f const Vector2f::get_unit_y() {
    return Vector2f{0.0f, 1.0f};
}





Vector3f::Vector3f(float x, float y, float z):
    x{x}, y{y}, z{z}
{}
Vector3f::Vector3f(Vector4f const &v):
    x{v.x}, y{v.y}, z{v.z}
{}
Vector3f::Vector3f(uint32_t uint_val):
    x{static_cast<float>(uint_val & 0xff000000U)/255.0f},
    y{static_cast<float>(uint_val & 0x00ff0000U)/255.0f},
    z{static_cast<float>(uint_val & 0x0000ff00U)/255.0f}
{}
Vector3f const Vector3f::operator-() const {
    return Vector3f{ -x, -y, -z };
}
Vector3f const Vector3f::operator+(Vector3f const &v) const {
    return Vector3f{ x + v.x, y + v.y, z + v.z };
}
Vector3f const Vector3f::operator-(Vector3f const &v) const {
    return Vector3f{ x - v.x, y - v.y, z - v.z };
}
Vector3f const Vector3f::operator*(Vector3f const &v) const {
    return Vector3f{ x * v.x, y * v.y, z * v.z };
}
Vector3f const Vector3f::operator*(float f) const {
    return Vector3f{ x * f, y * f, z * f };
}
Vector3f const Vector3f::operator/(float f) const {
    return Vector3f{ x / f, y / f, z / f };
}
Vector3f &Vector3f::operator+=(Vector3f const &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}
Vector3f &Vector3f::operator-=(Vector3f const &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}
Vector3f &Vector3f::operator*=(Vector3f const &v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}
Vector3f &Vector3f::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}
Vector3f &Vector3f::operator/=(float f) {
    x /= f;
    y /= f;
    z /= f;
    return *this;
}
float Vector3f::length() const {
    return sqrtf(x*x + y*y + z*z);
}
Vector3f const Vector3f::get_normalize() const {
    return this->operator/(this->length());
}
Vector3f &Vector3f::normalize() {
    return this->operator/=(this->length());
}
Vector3f &Vector3f::saturate() {
    x = x < 1.0f ? (x > 0.0f ? x : 0.0f) : 1.0f;
    y = y < 1.0f ? (y > 0.0f ? y : 0.0f) : 1.0f;
    z = z < 1.0f ? (z > 0.0f ? z : 0.0f) : 1.0f;
    return *this;
}
Vector3f &Vector3f::clamp(float min, float max) {
    x = x < max ? (x > min ? x : min) : max;
    y = y < max ? (y > min ? y : min) : max;
    z = z < max ? (z > min ? z : min) : max;
    return *this;
}

float Vector3f::inner(Vector3f const &v) const {
    return x * v.x + y * v.y + z * v.z;
}
Vector3f const Vector3f::cross(Vector3f const &v) const {
    return Vector3f{ y * v.z - z * v.y +
        z * v.x - x * v.z +
        x * v.y - y * v.x };
}
Vector3f const Vector3f::get_unit_x() {
    return Vector3f{1.0f, 0.0f, 0.0f};
}
Vector3f const Vector3f::get_unit_y() {
    return Vector3f{0.0f, 1.0f, 0.0f};
}
Vector3f const Vector3f::get_unit_z() {
    return Vector3f{0.0f, 0.0f, 1.0f};
}





Vector4f::Vector4f(float x, float y, float z, float w):
    x{x}, y{y}, z{z}, w{w}
{}
Vector4f::Vector4f(Vector3f const &v, float f):
    x{v.x}, y{v.y}, z{v.z}, w{f}
{}
Vector4f::Vector4f(uint32_t uint_val):
    x{static_cast<float>(uint_val & 0xff000000U)/255.0f},
    y{static_cast<float>(uint_val & 0x00ff0000U)/255.0f},
    z{static_cast<float>(uint_val & 0x0000ff00U)/255.0f},
    w{static_cast<float>(uint_val & 0x000000ffU)/255.0f}
{}
Vector4f const Vector4f::operator-() const {
    return Vector4f{ -x, -y, -z, -w };
}
Vector4f const Vector4f::operator+(Vector4f const &v) const {
    return Vector4f{ x + v.x, y + v.y, z + v.z, w + v.w };
}
Vector4f const Vector4f::operator-(Vector4f const &v) const {
    return Vector4f{ x - v.x, y - v.y, z - v.z, w - v.w };
}
Vector4f const Vector4f::operator*(Vector4f const &v) const {
    return Vector4f{ x * v.x, y * v.y, z * v.z, w * v.w };
}
Vector4f const Vector4f::operator*(float f) const {
    return Vector4f{ x * f, y * f, z * f, w * f };
}
Vector4f const Vector4f::operator/(float f) const {
    return Vector4f{ x / f, y / f, z / f, w / f };
}
Vector4f &Vector4f::operator+=(Vector4f const &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}
Vector4f &Vector4f::operator-=(Vector4f const &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}
Vector4f &Vector4f::operator*=(Vector4f const &v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return *this;
}
Vector4f &Vector4f::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    return *this;
}
Vector4f &Vector4f::operator/=(float f) {
    x /= f;
    y /= f;
    z /= f;
    w /= f;
    return *this;
}
float Vector4f::length() const {
    return sqrtf(x*x + y*y + z*z + w*w);
}
Vector4f const Vector4f::get_normalize() const {
    return this->operator/(this->length());
}
Vector4f &Vector4f::normalize() {
    return this->operator/=(this->length());
}
Vector4f &Vector4f::saturate() {
    x = x < 1.0f ? (x > 0.0f ? x : 0.0f) : 1.0f;
    y = y < 1.0f ? (y > 0.0f ? y : 0.0f) : 1.0f;
    z = z < 1.0f ? (z > 0.0f ? z : 0.0f) : 1.0f;
    w = w < 1.0f ? (w > 0.0f ? w : 0.0f) : 1.0f;
    return *this;
}
Vector4f &Vector4f::clamp(float min, float max) {
    x = x < max ? (x > min ? x : min) : max;
    y = y < max ? (y > min ? y : min) : max;
    z = z < max ? (z > min ? z : min) : max;
    w = w < max ? (w > min ? w : min) : max;
    return *this;
}
float Vector4f::inner(Vector4f const &v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
}
Vector4f const Vector4f::cross(Vector4f const &v) const {
    return Vector4f{ y * v.z - z * v.y +
        z * v.w - w * v.z +
        w * v.x - x * v.w +
        x * v.y - y * v.x };
}
Vector4f const Vector4f::get_unit_x() {
    return Vector4f{1.0f, 0.0f, 0.0f, 0.0f};
}
Vector4f const Vector4f::get_unit_y() {
    return Vector4f{0.0f, 1.0f, 0.0f, 0.0f};
}
Vector4f const Vector4f::get_unit_z() {
    return Vector4f{0.0f, 0.0f, 1.0f, 0.0f};
}
Vector4f const Vector4f::get_unit_w() {
    return Vector4f{0.0f, 0.0f, 0.0f, 1.0f};
}