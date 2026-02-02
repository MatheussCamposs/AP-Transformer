#include "matrix.hpp"

Matrix ReLU(const Matrix& matrix) {
  Matrix out(matrix.rows, matrix.cols);
  for(int i = 0; i < matrix.rows; i++) {
    for(int j = 0; j < matrix.cols; j++) {
      out(i, j) = std::max(0.0, matrix(i, j));
    }
  }
  return out;
}
