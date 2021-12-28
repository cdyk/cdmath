#pragma once
#include <cstddef>

/** 2D vector */
template<typename T>
struct Vec2
{
  union {
    struct {
      T x;
      T y;
    };
    T data[2];
  };
  T& operator[](size_t i) { return data[i]; }
  const T& operator[](size_t i) const { return data[i]; }
};
typedef Vec2<float>    Vec2f;
typedef Vec2<double>   Vec2d;
typedef Vec2<int>      Vec2i;
typedef Vec2<unsigned> Vec2u;
template<typename T> Vec2<T> makeVec2(T x, T y) {   Vec2<T> u; u.x = x;    u.y = y;    return u; }
template<typename T> Vec2<T> makeVec2(const T* p) { Vec2<T> u; u.x = p[0]; u.y = p[1]; return u; }

/** 3D vector */
template<typename T>
struct Vec3
{
  union {
    struct {
      T x;
      T y;
      T z;
    };
    T data[3];
  };
  T& operator[](size_t i) { return data[i]; }
  const T& operator[](size_t i) const { return data[i]; }
};
typedef Vec3<float>    Vec3f;
typedef Vec3<double>   Vec3d;
typedef Vec3<int>      Vec3i;
typedef Vec3<unsigned> Vec3u;
template<typename T> Vec3<T> makeVec3(T x, T y, T z) { Vec3<T> u; u.x = x;    u.y = y;    u.z = z;    return u; }
template<typename T> Vec3<T> makeVec3(const T* p) {    Vec3<T> u; u.x = p[0]; u.y = p[1]; u.z = p[2]; return u; }

/** 4D vector */
template<typename T>
struct Vec4
{
  union {
    struct {
      T x;
      T y;
      T z;
      T w;
    };
    T data[4];
  };
  T& operator[](size_t i) { return data[i]; }
  const T& operator[](size_t i) const { return data[i]; }
};
typedef Vec4<float>    Vec4f;
typedef Vec4<double>   Vec4d;
typedef Vec4<int>      Vec4i;
typedef Vec4<unsigned> Vec4u;
template<typename T> Vec4<T> makeVec4(T x, T y, T z, T w) { Vec4<T> u; u.x = x;    u.y = y;    u.z = z;    u.w = w;    return u; }
template<typename T> Vec4<T> makeVec4(const T* p) {         Vec4<T> u; u.x = p[0]; u.y = p[1]; u.z = p[2]; u.w = p[3]; return u; }


struct BBox3f
{
  BBox3f() = default;
  BBox3f(const BBox3f&) = default;
  BBox3f(const Vec3f& min, const Vec3f& max) : min(min), max(max) {}
  BBox3f(const BBox3f& bbox, float margin);

  union {
    struct {
      Vec3f min;
      Vec3f max;
    };
    float data[6];
  };
};

struct Mat3f
{
  Mat3f() = default;
  Mat3f(const Mat3f&) = default;
  Mat3f(const float* ptr) { for (unsigned i = 0; i < 3 * 3; i++) data[i] = ptr[i]; }
  Mat3f(float m00, float m01, float m02,
        float m10, float m11, float m12,
        float m20, float m21, float m22) :
    m00(m00), m10(m10), m20(m20),
    m01(m01), m11(m11), m21(m21),
    m02(m02), m12(m12), m22(m22)
  {}


  union {
    struct {
      float m00;
      float m10;
      float m20;
      float m01;
      float m11;
      float m21;
      float m02;
      float m12;
      float m22;
    };
    Vec3f cols[3];
    float data[3 * 3];
  };
};


struct Mat3x4f
{
  Mat3x4f() = default;
  Mat3x4f(const Mat3x4f&) = default;
  Mat3x4f(const float* ptr) { for (unsigned i = 0; i < 4 * 3; i++) data[i] = ptr[i]; }

  union {
    struct {
      float m00;
      float m10;
      float m20;

      float m01;
      float m11;
      float m21;

      float m02;
      float m12;
      float m22;

      float m03;
      float m13;
      float m23;
    };
    Vec3f cols[4];
    float data[4 * 3];
  };
};


inline Vec2f makeVec2f(float x)                { return makeVec2(x, x); }
inline Vec2f makeVec2f(float x, float y)       { return makeVec2(x, y); }
inline Vec2f makeVec2f(const float* p)         { return makeVec2(p); }
inline Vec2f makeVec2f(const Vec2f& v)         { return makeVec2(v.data); }
inline Vec2f makeVec2f(const Vec3f& v)         { return makeVec2(v.data); }
inline Vec2f makeVec2f(const Vec4f& v)         { return makeVec2(v.data); }
inline Vec2d makeVec2d(double x)               { return makeVec2(x, x); }
inline Vec2d makeVec2d(double x, double y)     { return makeVec2(x, y); }
inline Vec2d makeVec2d(const double* p)        { return makeVec2(p); }
inline Vec2d makeVec2d(const Vec2d& v)         { return makeVec2(v.data); }
inline Vec2d makeVec2d(const Vec3d& v)         { return makeVec2(v.data); }
inline Vec2d makeVec2d(const Vec4d& v)         { return makeVec2(v.data); }
inline Vec2i makeVec2i(int x)                  { return makeVec2(x, x); }
inline Vec2i makeVec2i(int x, int y)           { return makeVec2(x, y); }
inline Vec2i makeVec2i(const int* p)           { return makeVec2(p); }
inline Vec2i makeVec2i(const Vec2i& v)         { return makeVec2(v.data); }
inline Vec2i makeVec2i(const Vec3i& v)         { return makeVec2(v.data); }
inline Vec2i makeVec2i(const Vec4i& v)         { return makeVec2(v.data); }
inline Vec2u makeVec2u(unsigned x)             { return makeVec2(x, x); }
inline Vec2u makeVec2u(unsigned x, unsigned y) { return makeVec2(x, y); }
inline Vec2u makeVec2u(const unsigned* p)      { return makeVec2(p); }
inline Vec2u makeVec2u(const Vec2u& v)         { return makeVec2(v.data); }
inline Vec2u makeVec2u(const Vec3u& v)         { return makeVec2(v.data); }
inline Vec2u makeVec2u(const Vec4u& v)         { return makeVec2(v.data); }

inline Vec3f makeVec3f(float x)                            { return makeVec3(x, x, x); }
inline Vec3f makeVec3f(float x, float y, float z)          { return makeVec3(x, y, z); }
inline Vec3f makeVec3f(const float* p)                     { return makeVec3(p); }
inline Vec3f makeVec3f(const Vec3f& v)                     { return makeVec3(v.data); }
inline Vec3f makeVec3f(const Vec4f& v)                     { return makeVec3(v.data); }
inline Vec3d makeVec3d(double x)                           { return makeVec3(x, x, x); }
inline Vec3d makeVec3d(double x, double y, double z)       { return makeVec3(x, y, z); }
inline Vec3d makeVec3d(const double* p)                    { return makeVec3(p); }
inline Vec3d makeVec3d(const Vec3d& v)                     { return makeVec3(v.data); }
inline Vec3d makeVec3d(const Vec4d& v)                     { return makeVec3(v.data); }
inline Vec3i makeVec3i(int x)                              { return makeVec3(x, x, x); }
inline Vec3i makeVec3i(int x, int y, int z)                { return makeVec3(x, y, z); }
inline Vec3i makeVec3i(const int* p)                       { return makeVec3(p); }
inline Vec3i makeVec3i(const Vec3i& v)                     { return makeVec3(v.data); }
inline Vec3i makeVec3i(const Vec4i& v)                     { return makeVec3(v.data); }
inline Vec3u makeVec3u(unsigned x)                         { return makeVec3(x, x, x); }
inline Vec3u makeVec3u(unsigned x, unsigned y, unsigned z) { return makeVec3(x, y, z); }
inline Vec3u makeVec3u(const unsigned* p)                  { return makeVec3(p); }
inline Vec3u makeVec3u(const Vec3u& v)                     { return makeVec3(v.data); }
inline Vec3u makeVec3u(const Vec4u& v)                     { return makeVec3(v.data); }

inline Vec4f makeVec4f(float x)                                        { return makeVec4(x, x, x, x); }
inline Vec4f makeVec4f(float x, float y, float z, float w)             { return makeVec4(x, y, z, w); }
inline Vec4f makeVec4f(const float* p)                                 { return makeVec4(p); }
inline Vec4f makeVec4f(const Vec4f& v)                                 { return makeVec4(v.data); }
inline Vec4d makeVec4d(double x)                                       { return makeVec4(x, x, x, x); }
inline Vec4d makeVec4d(double x, double y, double z, double w)         { return makeVec4(x, y, z, w); }
inline Vec4d makeVec4d(const double* p)                                { return makeVec4(p); }
inline Vec4d makeVec4d(const Vec4d& v)                                 { return makeVec4(v.data); }
inline Vec4i makeVec4i(int x)                                          { return makeVec4(x, x, x, x); }
inline Vec4i makeVec4i(int x, int y, int z, int w)                     { return makeVec4(x, y, z, w); }
inline Vec4i makeVec4i(const int* p)                                   { return makeVec4(p); }
inline Vec4i makeVec4i(const Vec4i& v)                                 { return makeVec4(v.data); }
inline Vec4u makeVec4u(unsigned x)                                     { return makeVec4(x, x, x, x); }
inline Vec4u makeVec4u(unsigned x, unsigned y, unsigned z, unsigned w) { return makeVec4(x, y, z, w); }
inline Vec4u makeVec4u(const unsigned* p)                              { return makeVec4(p); }
inline Vec4u makeVec4u(const Vec4u& v)                                 { return makeVec4(v.data); }
