#pragma once
#include <cmath>

class Vector3f;
class Vector4f;

class alignas(sizeof(float)*4) Vector3f final {
public:
    union { float x, r; };
    union { float y, g; };
    union { float z, b; };
    Vector3f(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    explicit Vector3f(Vector4f const &);
    Vector3f(Vector3f const &) = default;
    Vector3f &operator=(Vector3f const &) = default;
    Vector3f const operator+(Vector3f const &) const;
    Vector3f const operator-(Vector3f const &) const;
    Vector3f const operator*(float) const;
    Vector3f const operator/(float) const;
    Vector3f &operator+=(Vector3f const &);
    Vector3f &operator-=(Vector3f const &);
    Vector3f &operator*=(float);
    Vector3f &operator/=(float);
    float length() const;
    Vector3f &normalize();
    float inner(Vector3f const &) const;
    Vector3f const cross(Vector3f const &) const;

    static Vector3f const get_unit_x();
    static Vector3f const get_unit_y();
    static Vector3f const get_unit_z();
};
class alignas(sizeof(float)*4) Vector4f final {
public:
    union { float x, r; };
    union { float y, g; };
    union { float z, b; };
    union { float w, a; };
    Vector4f(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
    explicit Vector4f(Vector3f const &, float = 0.0f);
    Vector4f(Vector4f const &) = default;
    Vector4f &operator=(Vector4f const &) = default;
    Vector4f const operator+(Vector4f const &) const;
    Vector4f const operator-(Vector4f const &) const;
    Vector4f const operator*(float) const;
    Vector4f const operator/(float) const;
    Vector4f &operator+=(Vector4f const &);
    Vector4f &operator-=(Vector4f const &);
    Vector4f &operator*=(float);
    Vector4f &operator/=(float);
    float length() const;
    Vector4f &normalize();
    float inner(Vector4f const &) const;
    Vector4f const cross(Vector4f const &) const;

    static Vector4f const get_unit_x();
    static Vector4f const get_unit_y();
    static Vector4f const get_unit_z();
    static Vector4f const get_unit_w();
};