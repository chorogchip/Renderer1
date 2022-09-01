#include "Matrixes.h"


Matrix4x4f::Matrix4x4f():
    m()
{}
#define a(x) l.begin()[x]
#define arr(x) a(x), a(x+1), a(x+2), a(x+3)
Matrix4x4f::Matrix4x4f(std::initializer_list<float> l):
    m{ arr(0), arr(4), arr(8), arr(12) }
{}
#undef a
#undef arr

#define a(v) v.x, v.y, v.z, v.w
Matrix4x4f::Matrix4x4f(Vector4f const &v1, Vector4f const &v2, Vector4f const &v3, Vector4f const &v4):
    m{ a(v1), a(v2), a(v3), a(v4) }
{}
#undef a

Matrix4x4f const Matrix4x4f::operator+(Matrix4x4f const &mat) const {
    Matrix4x4f ret;
    for (int i = 0; i != sizeof(m)/sizeof(float); ++i)
        ret.m[i] = m[i] + mat.m[i];
    return ret;
}
Matrix4x4f const Matrix4x4f::operator-(Matrix4x4f const &mat) const {
    Matrix4x4f ret;
    for (int i = 0; i != sizeof(m)/sizeof(float); ++i)
        ret.m[i] = m[i] - mat.m[i];
    return ret;
}
Matrix4x4f const Matrix4x4f::operator*(float f) const {
    Matrix4x4f ret;
    for (int i = 0; i != sizeof(m)/sizeof(float); ++i)
        ret.m[i] = m[i] * f;
    return ret;
}
Matrix4x4f const Matrix4x4f::operator/(float f) const {
    Matrix4x4f ret;
    for (int i = 0; i != sizeof(m)/sizeof(float); ++i)
        ret.m[i] = m[i] / f;
    return ret;
}
Matrix4x4f &Matrix4x4f::operator+=(Matrix4x4f const &mat) {
    for (int i = 0; i != sizeof(m)/sizeof(float); ++i)
        m[i] += mat.m[i];
    return *this;
}
Matrix4x4f &Matrix4x4f::operator-=(Matrix4x4f const &mat) {
    for (int i = 0; i != sizeof(m)/sizeof(float); ++i)
        m[i] -= mat.m[i];
    return *this;
}
Matrix4x4f &Matrix4x4f::operator*=(float f) {
    for (int i = 0; i != sizeof(m)/sizeof(float); ++i)
        m[i] *= f;
    return *this;
}
Matrix4x4f &Matrix4x4f::operator/=(float f) {
    for (int i = 0; i != sizeof(m)/sizeof(float); ++i)
        m[i] /= f;
    return *this;
}

Matrix4x4f const Matrix4x4f::operator*(Matrix4x4f const &mat) const {
    Matrix4x4f ret;
    for (int i = 0; i != 4; ++i)
        for (int j = 0; j != 4; ++j) {
            float &ind = ret.m[i*4+j];
            ind = 0.0f;
            for (int k = 0; k != 4; ++k)
                ind += m[i*4+k] * mat.m[k*4+j];
        }
    return ret;
}
Matrix4x4f &Matrix4x4f::operator*=(Matrix4x4f const &mat) {
    return *this = this->operator*(mat);
}
Vector4f const Matrix4x4f::operator*(Vector4f const &v) const {
    return Vector4f {
        m[ 0]*v.x + m[ 1]*v.y + m[ 2]*v.z + m[ 3]*v.w ,
        m[ 4]*v.x + m[ 5]*v.y + m[ 6]*v.z + m[ 7]*v.w ,
        m[ 8]*v.x + m[ 9]*v.y + m[10]*v.z + m[11]*v.w ,
        m[12]*v.x + m[13]*v.y + m[14]*v.z + m[15]*v.w
    };
}

Matrix4x4f const Matrix4x4f::transpose() const {
    return Matrix4x4f{
        m[0], m[4], m[ 8], m[12],
        m[1], m[5], m[ 9], m[13],
        m[2], m[6], m[10], m[14],
        m[3], m[7], m[11], m[15]
    };
}
Matrix4x4f const Matrix4x4f::get_identity() {
    return Matrix4x4f{
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_trasnpose(Vector3f const &v) {
    return Matrix4x4f{
        1.0f, 0.0f, 0.0f, v.x,
        0.0f, 1.0f, 0.0f, v.y,
        0.0f, 0.0f, 1.0f, v.z,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_trasnpose(Vector4f const &v) {
    return Matrix4x4f{
        1.0f, 0.0f, 0.0f, v.x,
        0.0f, 1.0f, 0.0f, v.y,
        0.0f, 0.0f, 1.0f, v.z,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_trasnpose(float x, float y, float z) {
    return Matrix4x4f{
        1.0f, 0.0f, 0.0f, x,
        0.0f, 1.0f, 0.0f, y,
        0.0f, 0.0f, 1.0f, z,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_scale(float f) {
    return Matrix4x4f{
        f, 0.0f, 0.0f, 0.0f,
        0.0f,    f, 0.0f, 0.0f,
        0.0f, 0.0f,    f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_scale(Vector3f const &v) {
    return Matrix4x4f{
        v.x , 0.0f, 0.0f, 0.0f,
        0.0f,  v.y, 0.0f, 0.0f,
        0.0f, 0.0f,  v.z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_scale(Vector4f const &v) {
    return Matrix4x4f{
        v.x , 0.0f, 0.0f, 0.0f,
        0.0f,  v.y, 0.0f, 0.0f,
        0.0f, 0.0f,  v.z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_scale(float x, float y, float z) {
    return Matrix4x4f{
        x , 0.0f, 0.0f, 0.0f,
        0.0f,    y, 0.0f, 0.0f,
        0.0f, 0.0f,    z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_rotate_x(float theta) {
    float sinT{sinf(theta)};
    float cosT{cosf(theta)};
    return Matrix4x4f{
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, cosT,-sinT, 0.0f,
        0.0f, sinT, cosT, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_rotate_y(float theta) {
    float sinT{sinf(theta)};
    float cosT{cosf(theta)};
    return Matrix4x4f{
        cosT, 0.0f, sinT, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -sinT, 0.0f, cosT, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_rotate_z(float theta) {
    float sinT{sinf(theta)};
    float cosT{cosf(theta)};
    return Matrix4x4f{
        cosT,-sinT, 0.0f, 0.0f,
        sinT, cosT, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}
Matrix4x4f const Matrix4x4f::get_projection(float fov_Y, float aspect, float n, float f) {
    float tmp{1.0f/tanf(fov_Y/2.0f)};
    return Matrix4x4f{
        tmp/aspect, 0.0f, 0.0f, 0.0f,
        0.0f, tmp, 0.0f, 0.0f,
        0.0f, 0.0f, (f+n)/(n-f), 2*n*f/(n-f),
        0.0f, 0.0f, -1.0f, 0.0f
    };
}