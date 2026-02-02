#include "matrix.hpp"
#include "random.hpp"

#include <stdexcept>

Matrix::Matrix(int rows_, int cols_) : rows(rows_), cols(cols_), data(rows_ * cols_, 0.0) {}

double& Matrix::operator()(int row, int col) {
  return data[row * cols + col];
}

const double& Matrix::operator()(int row, int col) const {
  return data[row * cols + col];
}

Matrix Matrix::operator+(const Matrix& other) const {
  if(rows != other.rows or cols != other.cols)
    throw std::runtime_error("Error: Sum of incompatible matrices");
  Matrix out(rows, cols);
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      out(i, j) = (*this)(i, j) + other(i, j); 
    }
  }
  return out;
}

Matrix Matrix::operator*(const Matrix& other) const {
  if(cols != other.rows)
    throw std::runtime_error("Error: Multiplication of incompatible matrices");
  Matrix out(rows, other.cols);
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < other.cols; j++) {
      for(int k = 0; k < cols; k++) {
        out(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  return out; 
}

Matrix Matrix::operator*(double scalar) const {
  Matrix out(rows, cols);
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      out(i, j) = (*this)(i, j) * scalar;
    }
  }
  return out;
}

Matrix Matrix::operator/(double scalar) const {
  if(scalar == 0.0) 
    throw std::runtime_error("Error: Trying to divide by zero");
  Matrix out(rows, cols);
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      out(i, j) = (*this)(i, j) / scalar;
    }
  }
  return out;
}

void Matrix::randomize(double min, double max) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      (*this)(i, j) = randomFloat(min, max);
    }
  }
}

Matrix Matrix::identity(int n) {
  Matrix out(n, n);
  for(int i = 0; i < n; i++) {
    out(i, i) = 1.0;
  }
  return out;
}

Matrix Matrix::transpose(const Matrix& matrix) {
  Matrix out(matrix.cols, matrix.rows);
  for(int i = 0; i < matrix.cols; i++) {
    for(int j = 0; j < matrix.rows; j++) {
      out(i, j) = matrix(j, i);
    }
  }
  return out;
}
