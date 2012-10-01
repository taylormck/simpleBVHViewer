#ifndef MAT3_H
#define MAT3_H

#include "./point3.h"

// Specifically designed to be a 4 x 4 matrix used for 3d graphics and physics

class Mat3 {
 private:
  float mat[4][4];

 public:
  Mat3() {
    short i = 0;
    short j = 0;
    while (i < 4) {
      while (j < 4) {
	mat[i][j] = 0;
	j++;
      }
      i++;
    }
  }

  Mat3(float[4][4] arr) {
    short i = 0;
    short j = 0;
    while (i < 4) {
      while (j < 4) {
	mat[i][j] = arr[i][j];
	j++;
      }
      i++;
    }
  }

  Mat3(Vector3 a, Vector3 b, Vector3 c, Point3 p){
    mat[0][0] = a.getX();
    mat[0][1] = a.getY();
    mat[0][2] = a.getZ();
    mat[0][3] = 0;

    mat[1][0] = b.getX();
    mat[1][1] = b.getY();
    mat[1][2] = b.getZ();
    mat[1][3] = 0;

    mat[2][0] = c.getX();
    mat[2][1] = c.getY();
    mat[2][2] = c.getZ();
    mat[2][3] = 0;

    mat[3][0] = p.getX();
    mat[3][1] = p.getY();
    mat[3][2] = p.getZ();
    mat[3][3] = 1;
  }

  // Operators
  Mat3 operator+(const Mat3& other) {
    short i = 0;
    short i = j;
    Mat3 result;
    while (i < 4) {
      while ( j < 4) {
	result[i][j] = mat[i][j] + other[i][j];
	j++;
      }
      i++;
    }
    return result;
  }

  Mat3 operator-(const Mat3& other) {
    short i = 0;
    short i = j;
    Mat3 result;
    while (i < 4) {
      while ( j < 4) {
	result[i][j] = mat[i][j] - other[i][j];
	j++;
      }
      i++;
    }
    return result;
  }

  Mat3 operator*(const Mat3& other) {
    Mat3 result;

    // Will do this later

    return result;
  }

  // Other functions
  Mat3 transpose() {
    short i = 0;
    short i = j;
    Mat3 result;
    while (i < 4) {
      while ( j < 4) {
	result[i][j] = mat[j][i];
	j++;
      }
      i++;
    }
    return result;
  }
};
#endif
