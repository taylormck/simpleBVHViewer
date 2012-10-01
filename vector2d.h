#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

class Vector2d {
 private:
  float x;
  float y;

 public:
  Vector2d() : x(0), y(0) {}
  Vector2d(float _x, float _y) : x(_x), y(_y) {}
  ~Vector2d() {}

  float getX() const { return x; }
  float getY() const { return y; }
  float setX(float _x) { x = _x; }
  float setY(float _y) { y = _y; }

  Vector2d operator+(const Vector2d& v) {
    return Vector2d(x + v.x, y + v.y);
  }

  Vector2d operator-(const Vector2d& v) {
    return Vector2d(x - v.x, y - v.y);
  }

  Vector2d operator*(float alpha) {
    return Vector2d(x * alpha, y * alpha);
  }

  Vector2d operator/(float alpha) {
    return Vector2d(x / alpha, y / alpha);
  }

  //------------------------------------------------------------
  // While this isn't technically correct, it's useful for
  // quickly modifying the Vector
  //------------------------------------------------------------
  Vector2d operator*(const Vector2d& v) {
    return Vector2d(x * v.x, y * v.y);
  }

  float dot(Vector2d v) {
    return x * v.x + y * v.y;
  }

  float magnitude() {
    return sqrt(x * x + y * y);
  }
};

static Vector2d operator*(float alpha, const Vector2d& v) {
  return Vector2d(alpha * v.getX(), alpha * v.getY());
}

#endif
