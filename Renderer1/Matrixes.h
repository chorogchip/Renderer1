#pragma once
#include <initializer_list>
#include <cmath>

#include "Vectors.h"

class alignas(sizeof(float)*16) Matrix4x4f final {
public:
    float m[16];
    Matrix4x4f();
    explicit Matrix4x4f(std::initializer_list<float>);
    explicit Matrix4x4f(Vector4f const &, Vector4f const &, Vector4f const &, Vector4f const &);
    Matrix4x4f(Matrix4x4f const &) = default;
    Matrix4x4f const operator+(Matrix4x4f const &) const;
    Matrix4x4f const operator-(Matrix4x4f const &) const;
    Matrix4x4f const operator*(float) const;
    Matrix4x4f const operator/(float) const;
    Matrix4x4f &operator+=(Matrix4x4f const &);
    Matrix4x4f &operator-=(Matrix4x4f const &);
    Matrix4x4f &operator*=(float);
    Matrix4x4f &operator/=(float);

    Matrix4x4f const operator*(Matrix4x4f const &) const;
    Matrix4x4f &operator*=(Matrix4x4f const &);
    Vector4f const operator*(Vector4f const &) const;

    Matrix4x4f const transpose() const;
    // Matrix4x4f const inverse() const;  // nooo

    static Matrix4x4f const get_identity();
    static Matrix4x4f const get_trasnpose(Vector3f const &);
    static Matrix4x4f const get_trasnpose(Vector4f const &);
    static Matrix4x4f const get_trasnpose(float x, float y, float z);
    static Matrix4x4f const get_scale(float);
    static Matrix4x4f const get_scale(Vector3f const &);
    static Matrix4x4f const get_scale(Vector4f const &);
    static Matrix4x4f const get_scale(float x, float y, float z);
    static Matrix4x4f const get_rotate_x(float theta);
    static Matrix4x4f const get_rotate_y(float theta);
    static Matrix4x4f const get_rotate_z(float theta);
    static Matrix4x4f const get_projection(float fov_Y, float aspect, float n, float f);
};
