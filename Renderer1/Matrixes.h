#pragma once
#include <initializer_list>
#include <cmath>

#include "Vectors.h"

class Matrix3x3f;
class Matrix4x4f;

class alignas(sizeof(float)*16) Matrix3x3f final {
public:
    float m[12];
    Matrix3x3f();
    explicit Matrix3x3f(std::initializer_list<float>);
    explicit Matrix3x3f(Vector3f const &, Vector3f const &, Vector3f const &);
    Matrix3x3f(Matrix3x3f const &) = default;
    explicit Matrix3x3f(Matrix4x4f const &);
    /*
    Matrix3x3f const operator+(Matrix3x3f const &) const;
    Matrix3x3f const operator-(Matrix3x3f const &) const;
    Matrix3x3f const operator*(float) const;
    Matrix3x3f const operator/(float) const;
    Matrix3x3f &operator+=(Matrix4x4f const &);
    Matrix3x3f &operator-=(Matrix4x4f const &);
    Matrix3x3f &operator*=(float);
    Matrix3x3f &operator/=(float);

    Matrix3x3f const operator*(Matrix3x3f const &) const;
    Matrix3x3f &operator*=(Matrix3x3f const &);*/
    Vector3f const operator*(Vector3f const &) const;
};

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
    static Matrix4x4f const get_viewport(float w, float h, float min_x, float min_y, float min_z, float max_z);
};
