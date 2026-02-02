struct TransformerLayer {
  SingleHeadAttention sha;
  FeedForwardNetwork ffn;

  TransformerLayer() {}

  Matrix forward(const Matrix& input) {
    Matrix X = input;
    X = LayerNorm(X + sha.forward(X));
    X = LayerNorm(X + ffn.forward(X));
    return X;
  }
};
