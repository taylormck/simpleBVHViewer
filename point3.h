#ifndef POINT3_H
#define POINT3_H

#include "./vector3.h"

class Point3 {
 private:
  float x;
  float y;
  float z;

 public:
  Point3()
    : x(0), y(0), z(0){}
  Point3(float _x, float _y, float _z)
    : x(_x), y(_y), z(_z) {}
  ~Point3() {}

  float getX() const { return x; }
  float getY() const { return y; }
  float getZ() const { return z; }
  float setX(float _x) { x = _x; }
  float setY(float _y) { y = _y; }
  float setZ(float _z) { z = _z; }

  Point3 operator+(const Vector3& v) {
    return Point3(x + v.getX(), y + v.getY(), z + v.getZ());
  }

  Point3 operator-(const Vector3& v) {
    return Point3(x - v.getX(), y - v.getY(), z - v.getZ());
  }

  Vector3 operator-(const Point3& p) {
    return Vector3(x - p.x, y - p.y, z - p.z);
  }
};
#endif
