#pragma once
#include <cstddef>
#include <cfloat>

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

/** 2D bounding box */
template<typename T>
struct BBox2
{
  union {
    struct {
      Vec2<T> min;
      Vec2<T> max;
    };
    T data[4];
  };
};
typedef BBox2<float> BBox2f;
typedef BBox2<double> BBox2d;
template<typename T> BBox2<T> makeBBox(const Vec2<T>& min, const Vec2<T>& max) { BBox2<T> box; box.min = min; box.max = max; return box; }

/** 3D bounding box */
template<typename T>
struct BBox3
{

  union {
    struct {
      Vec3<T> min;
      Vec3<T> max;
    };
    T data[6];
  };
};
typedef BBox3<float> BBox3f;
typedef BBox3<double> BBox3d;
template<typename T> BBox3<T> makeBBox(const Vec3<T>& min, const Vec3<T>& max) { BBox3<T> box; box.min = min; box.max = max; return box; }

template<typename T>
struct Mat3
{
  union {
    struct {
      float c0r0;
      float c0r1;
      float c0r2;
      float c1r0;
      float c1r1;
      float c1r2;
      float c2r0;
      float c2r1;
      float c2r2;
    };
    Vec3<T> cols[3];
    float data[3 * 3];
  };
};
typedef Mat3<float> Mat3f;
typedef Mat3<double> Mat3d;

template<typename T>
Mat3<T> makeMat3(const Vec3<T>& c0, const Vec3<T>& c1, const Vec3<T>& c2)
{
  Mat3<T> m;
  m.cols[0] = c0;
  m.cols[1] = c1;
  m.cols[2] = c2;
  return m;
}

template<typename T>
Mat3<T> makeMat3(const T* p)
{
  Mat3<T> m;
  for(size_t i=0; i<3*3; i++) { m.data[i] = p[i]; }
  return m;
}

template<typename T>
Mat3<T> makeMatRowMajor3(T c0r0, T c1r0, T c2r0,
                         T c0r1, T c1r1, T c2r1,
                         T c0r2, T c1r2, T c2r2)
{
  Mat3<T> m;
  m.c0r0 = c0r0; m.c0r1 = c0r1; m.c0r2 = c0r2;
  m.c1r0 = c1r0; m.c1r1 = c1r1; m.c1r2 = c1r2;
  m.c2r0 = c2r0; m.c2r1 = c2r1; m.c2r2 = c2r2;
  return m;
}


template<typename T>
struct Mat3x4
{
  union {
    struct {
      float c0r0;
      float c0r1;
      float c0r2;
      float c1r0;
      float c1r1;
      float c1r2;
      float c2r0;
      float c2r1;
      float c2r2;
      float c3r0;
      float c3r1;
      float c3r2;
    };
    Vec3f cols[4];
    float data[4 * 3];
  };
};
typedef Mat3x4<float> Mat3x4f;
typedef Mat3x4<double> Mat3x4d;

template<typename T>
Mat3x4<T> makeMat3x4(const Vec3<T>& c0, const Vec3<T>& c1, const Vec3<T>& c2, const Vec3<T>& c3)
{
  Mat3<T> m;
  m.cols[0] = c0;
  m.cols[1] = c1;
  m.cols[2] = c2;
  m.cols[3] = c3;
  return m;
}

template<typename T>
Mat3x4<T> makeMat3x4(const T* p)
{
  Mat3<T> m;
  for(size_t i=0; i<4*3; i++) { m.data[i] = p[i]; }
  return m;
}

template<typename T>
Mat3x4<T> makeMatRowMajor3x4(T c0r0, T c1r0, T c2r0, T c3r0,
                             T c0r1, T c1r1, T c2r1, T c3r1,
                             T c0r2, T c1r2, T c2r2, T c3r2)
{
  Mat3<T> m;
  m.c0r0 = c0r0; m.c0r1 = c0r1; m.c0r2 = c0r2;
  m.c1r0 = c1r0; m.c1r1 = c1r1; m.c1r2 = c1r2;
  m.c2r0 = c2r0; m.c2r1 = c2r1; m.c2r2 = c2r2;
  m.c3r0 = c3r0; m.c3r1 = c3r1; m.c3r2 = c3r2;
  return m;
}



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

inline BBox2f makeEmptyBBox2f() { BBox2f box; box.min = makeVec2f(FLT_MAX); box.max = makeVec2f(-FLT_MAX); return box; }
inline BBox2d makeEmptyBBox2d() { BBox2d box; box.min = makeVec2d(DBL_MAX); box.max = makeVec2d(-DBL_MAX); return box; }
inline BBox3f makeEmptyBBox3f() { BBox3f box; box.min = makeVec3f(FLT_MAX); box.max = makeVec3f(-FLT_MAX); return box; }
inline BBox3d makeEmptyBBox3d() { BBox3d box; box.min = makeVec3d(DBL_MAX); box.max = makeVec3d(-DBL_MAX); return box; }

inline Mat3f makeMat3f(const Vec3f& c0, const Vec3f& c1, const Vec3f& c2) { return makeMat3(c0, c1, c2); }
inline Mat3d makeMat3d(const Vec3d& c0, const Vec3d& c1, const Vec3d& c2) { return makeMat3(c0, c1, c2); }
inline Mat3f makeMat3f(const float* p) { return makeMat3(p); }
inline Mat3d makeMat3d(const double* p) { return makeMat3(p); }
inline Mat3f makeMatRowMajor3f(float c0r0, float c1r0, float c2r0,
                               float c0r1, float c1r1, float c2r1,
                               float c0r2, float c1r2, float c2r2)
{
  return makeMatRowMajor3(c0r0, c1r0, c2r0,
                          c0r1, c1r1, c2r1,
                          c0r2, c1r2, c2r2);
}
inline Mat3d makeMatRowMajor3d(double c0r0, double c1r0, double c2r0,
                               double c0r1, double c1r1, double c2r1,
                               double c0r2, double c1r2, double c2r2)
{
  return makeMatRowMajor3(c0r0, c1r0, c2r0,
                          c0r1, c1r1, c2r1,
                          c0r2, c1r2, c2r2);
}
