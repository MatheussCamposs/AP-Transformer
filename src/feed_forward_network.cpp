struct FeedForwardNetwork {
  Matrix W1, W2;
  Matrix b1, b2;

  FeedForwardNetwork() : W1(dff, dmodel), b1(dff, 1), W2(dmodel, dff), b2(dmodel, 1) {
    W1.randomize();
    W2.randomize();
  }

  static Matrix ReLU(const Matrix& X) {
    Matrix out = X;
    for (int i = 0; i < X.rows; i++) {
      for (int j = 0; j < X.cols; j++) {
        out.data[i][j] = max(X.data[i][j], 0.0);
      }
    }
    return out;
  }

  static Matrix Linear(const Matrix& X, const Matrix& W, const Matrix& b) {
    Matrix Y = (W * X) + b;
    return Y;
  }

  Matrix forward(const Matrix& input) const {
    Matrix A1 = Linear(input, W1, b1);
    Matrix Z1 = ReLU(A1);
    Matrix A2 = Linear(Z1, W2, b2);
    return A2;
  }
};
