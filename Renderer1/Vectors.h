#pragma once
#include <cmath>
#include <algorithm>

class Vector2f;
class Vector3f;
class Vector4f;

class alignas(sizeof(float)*2) Vector2f final {
public:
    float x;
    float y;
    Vector2f();
    Vector2f(float x, float y);
    Vector2f(Vector2f const &) = default;
    explicit Vector2f(Vector3f const &);
    explicit Vector2f(Vector4f const &);
    Vector2f &operator=(Vector2f const &) = default;
    Vector2f const operator-() const;
    Vector2f const operator+(Vector2f const &) const;
    Vector2f const operator-(Vector2f const &) const;
    Vector2f const operator*(Vector2f const &) const;
    Vector2f const operator*(float) const;
    Vector2f const operator/(float) const;
    template<typename T> Vector2f const operator*(T) const = delete;
    template<typename T> Vector2f const operator/(T) const = delete;
    Vector2f &operator+=(Vector2f const &);
    Vector2f &operator-=(Vector2f const &);
    Vector2f &operator*=(Vector2f const &);
    Vector2f &operator*=(float);
    Vector2f &operator/=(float);
    template<typename T> Vector2f &operator*=(T) = delete;
    template<typename T> Vector2f &operator/=(T) = delete;
    float length() const;
    Vector2f const get_normalize() const;
    Vector2f &normalize();
    Vector2f &saturate();
    Vector2f &clamp(float min, float max);
    template<typename T, typename U> Vector2f &clamp(T, U) = delete;
    float inner(Vector2f const &) const;

    static Vector2f const get_unit_x();
    static Vector2f const get_unit_y();
};

class alignas(sizeof(float)*4) Vector3f final {
public:
    union { float x, r; };
    union { float y, g; };
    union { float z, b; };
    Vector3f();
    Vector3f(float x, float y, float z);
    explicit Vector3f(Vector4f const &);
    Vector3f(Vector3f const &) = default;
    explicit Vector3f(uint32_t);
    Vector3f &operator=(Vector3f const &) = default;
    Vector3f const operator-() const;
    Vector3f const operator+(Vector3f const &) const;
    Vector3f const operator-(Vector3f const &) const;
    Vector3f const operator*(Vector3f const &) const;
    Vector3f const operator*(float) const;
    Vector3f const operator/(float) const;
    template<typename T> Vector3f const operator*(T) const = delete;
    template<typename T> Vector3f const operator/(T) const = delete;
    Vector3f &operator+=(Vector3f const &);
    Vector3f &operator-=(Vector3f const &);
    Vector3f &operator*=(Vector3f const &);
    Vector3f &operator*=(float);
    Vector3f &operator/=(float);
    template<typename T> Vector3f &operator*=(T) = delete;
    template<typename T> Vector3f &operator/=(T) = delete;
    float length() const;
    Vector3f const get_normalize() const;
    Vector3f &normalize();
    Vector3f &saturate();
    Vector3f &clamp(float min, float max);
    template<typename T, typename U> Vector3f &clamp(T, U) = delete;
    float inner(Vector3f const &) const;
    Vector3f const cross(Vector3f const &) const;
    Vector3f const reflect(Vector3f const &normal) const;
    void swap(Vector3f &);

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
    Vector4f();
    Vector4f(float x, float y, float z, float w = 0.0f);
    explicit Vector4f(Vector3f const &, float = 0.0f);
    Vector4f(Vector4f const &) = default;
    explicit Vector4f(uint32_t);
    Vector4f &operator=(Vector4f const &) = default;
    Vector4f const operator-() const;
    Vector4f const operator+(Vector4f const &) const;
    Vector4f const operator-(Vector4f const &) const;
    Vector4f const operator*(Vector4f const &) const;
    Vector4f const operator*(float) const;
    Vector4f const operator/(float) const;
    template<typename T> Vector4f const operator*(T) const = delete;
    template<typename T> Vector4f const operator/(T) const = delete;
    Vector4f &operator+=(Vector4f const &);
    Vector4f &operator-=(Vector4f const &);
    Vector4f &operator*=(Vector4f const &);
    Vector4f &operator*=(float);
    Vector4f &operator/=(float);
    template<typename T> Vector4f &operator*=(T) = delete;
    template<typename T> Vector4f &operator/=(T) = delete;
    float length() const;
    Vector4f const get_normalize() const;
    Vector4f &normalize();
    Vector4f &saturate();
    Vector4f &clamp(float min, float max);
    template<typename T, typename U> Vector4f &clamp(T, U) = delete;
    float inner(Vector4f const &) const;
    Vector4f const cross(Vector4f const &) const;

    static Vector4f const get_unit_x();
    static Vector4f const get_unit_y();
    static Vector4f const get_unit_z();
    static Vector4f const get_unit_w();
};