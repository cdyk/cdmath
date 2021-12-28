#include "LinAlgOps.h"


Mat3f inverse(const Mat3f& M)
{
  const Vec3f& c0 = M.cols[0];
  const Vec3f& c1 = M.cols[1];
  const Vec3f& c2 = M.cols[2];

  Vec3f r0 = cross(c1, c2);
  Vec3f r1 = cross(c2, c0);
  Vec3f r2 = cross(c0, c1);

  float invDet = 1.f / dot(r2, c2);

  return makeMatRowMajor3f(invDet * r0.x, invDet * r0.y, invDet*r0.z,
                           invDet * r1.x, invDet * r1.y, invDet*r1.z,
                           invDet * r2.x, invDet * r2.y, invDet*r2.z);
}

Mat3f mul(const Mat3f& A, const Mat3f& B)
{
  float A00 = A.cols[0].x;  float A10 = A.cols[0].y;  float A20 = A.cols[0].z;
  float A01 = A.cols[1].x;  float A11 = A.cols[1].y;  float A21 = A.cols[1].z;
  float A02 = A.cols[2].x;  float A12 = A.cols[2].y;  float A22 = A.cols[2].z;

  float B00 = B.cols[0].x;  float B10 = B.cols[0].y;  float B20 = B.cols[0].z;
  float B01 = B.cols[1].x;  float B11 = B.cols[1].y;  float B21 = B.cols[1].z;
  float B02 = B.cols[2].x;  float B12 = B.cols[2].y;  float B22 = B.cols[2].z;

  return makeMatRowMajor3f(A00 * B00 + A01 * B10 + A02 * B20,
                           A00 * B01 + A01 * B11 + A02 * B21,
                           A00 * B02 + A01 * B12 + A02 * B22,

                           A10 * B00 + A11 * B10 + A12 * B20,
                           A10 * B01 + A11 * B11 + A12 * B21,
                           A10 * B02 + A11 * B12 + A12 * B22,

                           A20 * B00 + A21 * B10 + A22 * B20,
                           A20 * B01 + A21 * B11 + A22 * B21,
                           A20 * B02 + A21 * B12 + A22 * B22);
}

float getScale(const Mat3f& M)
{
  float sx = length(M.cols[0]);
  float sy = length(M.cols[1]);
  float sz = length(M.cols[2]);
  auto t = sx > sy ? sx : sy;
  return sz > t ? sz : t;
}


BBox3f transform(const Mat3x4f& M, const BBox3f& bbox)
{
  Vec3f p[8] = {
    mul(M, makeVec3f(bbox.min.x, bbox.min.y, bbox.min.z)),
    mul(M, makeVec3f(bbox.min.x, bbox.min.y, bbox.max.z)),
    mul(M, makeVec3f(bbox.min.x, bbox.max.y, bbox.min.z)),
    mul(M, makeVec3f(bbox.min.x, bbox.max.y, bbox.max.z)),
    mul(M, makeVec3f(bbox.max.x, bbox.min.y, bbox.min.z)),
    mul(M, makeVec3f(bbox.max.x, bbox.min.y, bbox.max.z)),
    mul(M, makeVec3f(bbox.max.x, bbox.max.y, bbox.min.z)),
    mul(M, makeVec3f(bbox.max.x, bbox.max.y, bbox.max.z))
  };
  return makeBBox(min(min(min(p[0], p[1]), min(p[2], p[3])), min(min(p[4], p[5]), min(p[6], p[7]))),
                  max(max(max(p[0], p[1]), max(p[2], p[3])), max(max(p[4], p[5]), max(p[6], p[7]))));
}
