#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

struct Matrix {
  int rows = 0;
  int cols = 0;

  std::vector<double> data;

  Matrix() = default;

  Matrix(int rows_, int cols_);

  double& operator()(int row, int col);

  const double& operator()(int row, int col) const;

  Matrix& operator=(const Matrix& other) = default;
  Matrix operator+(const Matrix& other) const;
  Matrix operator*(const Matrix& other) const;
  Matrix operator*(double scalar) const;
  Matrix operator/(double scalar) const;

  void randomize(double min = -1.0, double max = 1.0);

  static Matrix identity(int n);

  static Matrix transpose(const Matrix& matrix);
};

#endif
