#ifndef POINT2_H
#define POINT2_H

#include "./vector3.h"

class Point2d {
 private:
  float x;
  float y;

 public:
  Point2d()
    : x(0), y(0) {}
  Point2d(float _x, float _y)
    : x(_x), y(_y) {}
  ~Point2d() {}

  float getX() const { return x; }
  float getY() const { return y; }
  float setX(float _x) { x = _x; }
  float setY(float _y) { y = _y; }

  Point2d operator+(const Vector2d& v) {
    return Point2d(x + v.getX(), y + v.getY());
  }

  Point2d operator-(const Vector2d& v) {
    return Point2d(x - v.getX(), y - v.getY());
  }

  Vector2d operator-(const Point2d& p) {
    return Vector2d(x - p.x, y - p.y);
  }
};
#endif
