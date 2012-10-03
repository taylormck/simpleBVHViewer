#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

class Vector3 {
 private:
  float x;
  float y;
  float z;

 public:
  Vector3() : x(0), y(0), z(0) {}
  Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
  ~Vector3() {}

  float getX() const { return x; }
  float getY() const { return y; }
  float getZ() const { return z; }
  float setX(float _x) { x = _x; }
  float setY(float _y) { y = _y; }
  float setZ(float _z) { z = _z; }

  Vector3 operator+(const Vector3& v) {
    return Vector3(x + v.x, y + v.y, z + v.z);
  }

  Vector3 operator-(const Vector3& v) {
    return Vector3(x - v.x, y - v.y, z - v.z);
  }

  Vector3 operator*(float alpha) {
    return Vector3(x * alpha, y * alpha, z * alpha);
  }

  Vector3 operator/(float alpha) {
    return Vector3(x / alpha, y / alpha, z / alpha);
  }

  //------------------------------------------------------------
  // While this isn't technically correct, it's useful for
  // quickly modifying the Vector
  //------------------------------------------------------------
  Vector3 operator*(const Vector3& v) {
    return Vector3(x * v.x, y * v.y, z * v.z);
  }

  float dot(Vector3 v) {
    return x * v.x + y * v.y + z * v.z;
  }

  float magnitude() {
    return sqrt(x * x + y * y + z * z);
  }

  // Will need to create a cross product function
  float cross(Vector3 v) {
    return 0;
  }
};

static Vector3 operator*(float alpha, const Vector3& v) {
  return Vector3(alpha * v.getX(), alpha * v.getY(), alpha * v.getZ());
}

#endif
