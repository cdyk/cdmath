#pragma once
#include <cmath>
#include <cfloat>
#include "LinAlg.h"

template<typename T>
Vec2<T> operator*(const T a, const Vec2<T>& b)
{
  return makeVec2<T>(a * b.x,
                     a * b.y);
}

template<typename T>
Vec2<T> operator-(const Vec2<T>& a, const Vec2<T>& b)
{
  return makeVec2<T>(a.x - b.x,
                     a.y - b.y);
}

template<typename T>
Vec2<T> operator+(const Vec2<T>& a, const Vec2<T>& b)
{
  return makeVec2<T>(a.x + b.x,
                     a.y + b.y);
}

template<typename T>
Vec3<T> operator*(const T a, const Vec3<T>& b)
{
  return makeVec3<T>(a * b.x,
                     a * b.y,
                     a * b.z);
}

template<typename T>
Vec3<T> operator-(const Vec3<T>& a, const Vec3<T>& b)
{
  return makeVec3<T>(a.x - b.x,
                     a.y - b.y,
                     a.z - b.z);
}

template<typename T>
Vec3<T> operator+(const Vec3<T>& a, const Vec3<T>& b)
{
  return makeVec3<T>(a.x + b.x,
                     a.y + b.y,
                     a.z + b.z);
}

template<typename T>
Vec4<T> operator*(const T a, const Vec4<T>& b)
{
  return makeVec4<T>(a * b.x,
                     a * b.y,
                     a * b.z,
                     a * b.w);
}

template<typename T>
Vec4<T> operator-(const Vec4<T>& a, const Vec4<T>& b)
{
  return makeVec4<T>(a.x - b.x,
                     a.y - b.y,
                     a.z - b.z,
                     a.w - b.w);
}

template<typename T>
Vec4<T> operator+(const Vec4<T>& a, const Vec4<T>& b)
{
  return makeVec4<T>(a.x + b.x,
                     a.y + b.y,
                     a.z + b.z,
                     a.w + b.w);
}

template<typename T> Vec3<T> cross(const Vec3<T>& a, const Vec3<T>& b)
{
  return makeVec3<T>(a.y * b.z - a.z * b.y,
                     a.z * b.x - a.x * b.z,
                     a.x * b.y - a.y * b.x);
}

template<typename T> T dot(const Vec2<T>& a, const Vec2<T>& b) { return a.x * b.x + a.y * b.y; }
template<typename T> T dot(const Vec3<T>& a, const Vec3<T>& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
template<typename T> T dot(const Vec4<T>& a, const Vec4<T>& b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

template<typename T> T lengthSquared(const Vec2<T>& a) { return dot(a, a); }
template<typename T> T lengthSquared(const Vec3<T>& a) { return dot(a, a); }
template<typename T> T lengthSquared(const Vec4<T>& a) { return dot(a, a); }

template<typename T> T distanceSquared(const Vec2<T>& a, const Vec2<T>&b) { return lengthSquared(a - b); }
template<typename T> T distanceSquared(const Vec3<T>& a, const Vec3<T>&b) { return lengthSquared(a - b); }
template<typename T> T distanceSquared(const Vec4<T>& a, const Vec4<T>&b) { return lengthSquared(a - b); }

template<typename T> T length(const Vec2<T>& a) { return std::sqrt(dot(a, a)); }
template<typename T> T length(const Vec3<T>& a) { return std::sqrt(dot(a, a)); }
template<typename T> T length(const Vec4<T>& a) { return std::sqrt(dot(a, a)); }

template<typename T> T distance(const Vec2<T>& a, const Vec2<T>&b) { return length(a - b); }
template<typename T> T distance(const Vec3<T>& a, const Vec3<T>&b) { return length(a - b); }
template<typename T> T distance(const Vec4<T>& a, const Vec4<T>&b) { return length(a - b); }

template<typename T> Vec2<T> normalize(const Vec2<T>& a) { return (T(1) / length(a)) * a; }
template<typename T> Vec3<T> normalize(const Vec3<T>& a) { return (T(1) / length(a)) * a; }
template<typename T> Vec4<T> normalize(const Vec4<T>& a) { return (T(1) / length(a)) * a; }

template<typename T>
T* write(T* dst, const Vec2<T>& a)
{
  *dst++ = a.data[0];
  *dst++ = a.data[1];
  return dst;
}

template<typename T>
T* write(T* dst, const Vec3<T>& a)
{
  *dst++ = a.data[0];
  *dst++ = a.data[1];
  *dst++ = a.data[2];
  return dst;
}

template<typename T>
T* write(T* dst, const Vec4<T>& a)
{
  *dst++ = a.data[0];
  *dst++ = a.data[1];
  *dst++ = a.data[2];
  *dst++ = a.data[3];
  return dst;
}

template<typename T>
Vec2<T> max(const Vec2<T>& a, const Vec2<T>& b)
{
  return makeVec2<T>(a.x > b.x ? a.x : b.x,
                     a.y > b.y ? a.y : b.y);
}

template<typename T>
Vec3<T> max(const Vec3<T>& a, const Vec3<T>& b)
{
  return makeVec3<T>(a.x > b.x ? a.x : b.x,
                     a.y > b.y ? a.y : b.y,
                     a.z > b.z ? a.z : b.z);
}

template<typename T>
Vec4<T> max(const Vec4<T>& a, const Vec4<T>& b)
{
  return makeVec4<T>(a.x > b.x ? a.x : b.x,
                     a.y > b.y ? a.y : b.y,
                     a.z > b.z ? a.z : b.z,
                     a.w > b.w ? a.w : b.w);
}

inline Vec2f min(const Vec2f& a, const Vec2f& b)
{
  return makeVec2f(a.x < b.x ? a.x : b.x,
                   a.y < b.y ? a.y : b.y);
}

inline Vec3f min(const Vec3f& a, const Vec3f& b)
{
  return makeVec3f(a.x < b.x ? a.x : b.x,
                   a.y < b.y ? a.y : b.y,
                   a.z < b.z ? a.z : b.z);
}

inline Vec4f min(const Vec4f& a, const Vec4f& b)
{
  return makeVec4f(a.x < b.x ? a.x : b.x,
                   a.y < b.y ? a.y : b.y,
                   a.z < b.z ? a.z : b.z,
                   a.w < b.w ? a.w : b.w);
}

Mat3f inverse(const Mat3f& M);

Mat3f mul(const Mat3f& A, const Mat3f& B);

float getScale(const Mat3f& M);

inline float getScale(const Mat3x4f& M) { return getScale(Mat3f(M.data)); }

inline Vec3f mul(const Mat3f& A, const Vec3f& x)
{
  Vec3f r;
  for (unsigned k = 0; k < 3; k++) {
    r.data[k] = A.data[k] * x.data[0] + A.data[3 + k] * x.data[1] + A.data[6 + k] * x.data[2];
  }
  return r;
}


inline Vec3f mul(const Mat3x4f& A, const Vec3f& x)
{
  Vec3f r;
  for (unsigned k = 0; k < 3; k++) {
    r.data[k] = A.data[k] * x.data[0] + A.data[3 + k] * x.data[1] + A.data[6 + k] * x.data[2] + A.data[9 + k];
  }
  return r;
}

inline BBox3f createEmptyBBox3f()
{
  return BBox3f(makeVec3f(FLT_MAX, FLT_MAX, FLT_MAX),
                makeVec3f(-FLT_MAX, -FLT_MAX, -FLT_MAX));
}

inline BBox3f::BBox3f(const BBox3f& bbox, float margin) :
  min(bbox.min - makeVec3f(margin)),
  max(bbox.max + makeVec3f(margin))
{}

inline void engulf(BBox3f& target, const Vec3f& p)
{
  target.min = min(target.min, p);
  target.max = max(target.max, p);
}

inline void engulf(BBox3f& target, const BBox3f& other)
{
  target.min = min(target.min, other.min);
  target.max = max(target.max, other.max);
}

BBox3f transform(const Mat3x4f& M, const BBox3f& bbox);

inline float diagonal(const BBox3f& b) { return distance(b.min, b.max); }

inline bool isEmpty(const BBox3f& b) { return b.max.x < b.min.x; }

inline bool isNotEmpty(const BBox3f& b) { return b.min.x <= b.max.x; }

inline float maxSideLength(const BBox3f& b)
{
  auto l = b.max - b.min;
  auto t = l.x > l.y ? l.x : l.y;
  return l.z > t ? l.z : t;
}

inline bool isStrictlyInside(const BBox3f& a, const BBox3f& b)
{
  auto lx = a.min.x <= b.min.x;
  auto ly = a.min.y <= b.min.y;
  auto lz = a.min.z <= b.min.z;
  auto ux = b.max.x <= a.max.x;
  auto uy = b.max.y <= a.max.y;
  auto uz = b.max.z <= a.max.z;
  return lx && ly && lz && ux && uy && uz;
}

inline bool isNotOverlapping(const BBox3f& a, const BBox3f& b)
{
  auto lx = b.max.x < a.min.x;
  auto ly = b.max.y < a.min.y;
  auto lz = b.max.z < a.min.z;
  auto ux = a.max.x < b.min.x;
  auto uy = a.max.y < b.min.y;
  auto uz = a.max.z < b.min.z;
  return lx || ly || lz || ux || uy || uz;
}

inline bool isOverlapping(const BBox3f& a, const BBox3f& b) { return !isNotOverlapping(a, b); }

