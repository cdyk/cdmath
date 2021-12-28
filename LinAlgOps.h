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

inline float getScale(const Mat3x4f& M) { return getScale(makeMat3f(M.data)); }

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

template<typename T> BBox2<T> grow(const BBox2<T>& bbox, T margin)
{
  return makeBBox(bbox.min - makeVec3f(margin),
                  bbox.max + makeVec3f(margin));
}
template<typename T> BBox3<T> grow(const BBox3<T>& bbox, T margin)
{
  return makeBBox(bbox.min - makeVec3f(margin),
                  bbox.max + makeVec3f(margin));
}

template<typename T> BBox2<T> engulf(const BBox2<T>& bbox, const Vec2<T>& p)
{
  return makeBBox(min(bbox.min, p),
                  max(bbox.max, p));
}
template<typename T> BBox3<T> engulf(const BBox3<T>& bbox, const Vec3<T>& p)
{
  return makeBBox(min(bbox.min, p),
                  max(bbox.max, p));
}

template<typename T> BBox2<T> engulf(const BBox2<T>& bbox, const BBox2<T>& other)
{
  return makeBBox(min(bbox.min, other.min),
                  max(bbox.max, other.max));
}
template<typename T> BBox3<T> engulf(const BBox3<T>& bbox, const BBox3<T>& other)
{
  return makeBBox(min(bbox.min, other.min),
                  max(bbox.max, other.max));
}

template<typename T> T diagonal(const BBox2<T>& b) { return distance(b.min, b.max); }
template<typename T> T diagonal(const BBox3<T>& b) { return distance(b.min, b.max); }

template<typename T> bool isEmpty(const BBox2<T>& b) { return b.max.x < b.min.x; }
template<typename T> bool isEmpty(const BBox3<T>& b) { return b.max.x < b.min.x; }

template<typename T> bool isNotEmpty(const BBox2<T>& b) { return b.min.x <= b.max.x; }
template<typename T> bool isNotEmpty(const BBox3<T>& b) { return b.min.x <= b.max.x; }

template<typename T> T maxSideLength(const BBox2<T>& b)
{
  Vec2<T> l = b.max - b.min;
  return l.x > l.y ? l.x : l.y;
}
template<typename T> T maxSideLength(const BBox3<T>& b)
{
  Vec3<T> l = b.max - b.min;
  T t = l.x > l.y ? l.x : l.y;
  return l.z > t ? l.z : t;
}

template<typename T> bool isStrictlyInside(const BBox2<T>& a, const BBox2<T>& b)
{
  bool lx = a.min.x <= b.min.x;
  bool ly = a.min.y <= b.min.y;
  bool ux = b.max.x <= a.max.x;
  bool uy = b.max.y <= a.max.y;
  return lx && ly && ux && uy;
}
template<typename T> bool isStrictlyInside(const BBox3<T>& a, const BBox3<T>& b)
{
  bool lx = a.min.x <= b.min.x;
  bool ly = a.min.y <= b.min.y;
  bool lz = a.min.z <= b.min.z;
  bool ux = b.max.x <= a.max.x;
  bool uy = b.max.y <= a.max.y;
  bool uz = b.max.z <= a.max.z;
  return lx && ly && lz && ux && uy && uz;
}

template<typename T> bool isNotOverlapping(const BBox2<T>& a, const BBox2<T>& b)
{
  bool lx = b.max.x < a.min.x;
  bool ly = b.max.y < a.min.y;
  bool ux = a.max.x < b.min.x;
  bool uy = a.max.y < b.min.y;
  return lx || ly || ux || uy;
}
template<typename T> bool isNotOverlapping(const BBox3<T>& a, const BBox3<T>& b)
{
  bool lx = b.max.x < a.min.x;
  bool ly = b.max.y < a.min.y;
  bool lz = b.max.z < a.min.z;
  bool ux = a.max.x < b.min.x;
  bool uy = a.max.y < b.min.y;
  bool uz = a.max.z < b.min.z;
  return lx || ly || lz || ux || uy || uz;
}

template<typename T> bool isOverlapping(const BBox2<T>& a, const BBox2<T>& b) { return !isNotOverlapping(a, b); }
template<typename T> bool isOverlapping(const BBox3<T>& a, const BBox3<T>& b) { return !isNotOverlapping(a, b); }

BBox3f transform(const Mat3x4f& M, const BBox3f& bbox);
