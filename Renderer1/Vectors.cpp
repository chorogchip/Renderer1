#include "Vectors.h"

Vector3f::Vector3f(float x, float y, float z):
    x{x}, y{y}, z{z}
{}
Vector3f::Vector3f(Vector4f const &v):
    x{v.x}, y{v.y}, z{v.z}
{}
Vector3f const Vector3f::operator+(Vector3f const &v) const {
    return { x + v.x, y + v.y, z + v.z };
}
Vector3f const Vector3f::operator-(Vector3f const &v) const {
    return { x - v.x, y - v.y, z - v.z };
}
Vector3f const Vector3f::operator*(float f) const {
    return { x*f, y*f, z*f };
}
Vector3f const Vector3f::operator/(float f) const {
    return { x/f, y/f, z/f };
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
Vector3f &Vector3f::normalize() {
    float len{this->length()};
    return this->operator/=(len);
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
    return Vector3f(1.0f, 0.0f, 0.0f);
}
Vector3f const Vector3f::get_unit_y() {
    return Vector3f(0.0f, 1.0f, 0.0f);
}
Vector3f const Vector3f::get_unit_z() {
    return Vector3f(0.0f, 0.0f, 1.0f);
}


Vector4f::Vector4f(float x, float y, float z, float w):
    x{x}, y{y}, z{z}, w{w}
{}
Vector4f::Vector4f(Vector3f const &v, float f):
    x{v.x}, y{v.y}, z{v.z}, w{f}
{}
Vector4f const Vector4f::operator+(Vector4f const &v) const {
    return { x + v.x, y + v.y, z + v.z, w + v.w };
}
Vector4f const Vector4f::operator-(Vector4f const &v) const {
    return { x - v.x, y - v.y, z - v.z, w - v.w };
}
Vector4f const Vector4f::operator*(float f) const {
    return { x*f, y*f, z*f, w*f };
}
Vector4f const Vector4f::operator/(float f) const {
    return { x/f, y/f, z/f, w/f };
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
Vector4f &Vector4f::normalize() {
    float len{this->length()};
    return this->operator/=(len);
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
    return Vector4f(1.0f, 0.0f, 0.0f, 0.0f);
}
Vector4f const Vector4f::get_unit_y() {
    return Vector4f(0.0f, 1.0f, 0.0f, 0.0f);
}
Vector4f const Vector4f::get_unit_z() {
    return Vector4f(0.0f, 0.0f, 1.0f, 0.0f);
}
Vector4f const Vector4f::get_unit_w() {
    return Vector4f(0.0f, 0.0f, 0.0f, 1.0f);
}