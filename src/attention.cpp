struct SingleHeadSelfAttention() {
  Matrix Wq;
  Matrix Wk;
  Matrix Wv;

  SingleHeadSelfAttention() : Wq(n, dmodel), Wk(n, dmodel), Wv(n, dmodel) {
    Wq.randomize();
    Wk.randomize();
    Wv.randomize();
  }

  Matrix forward(const Matrix& X) {
    Matrix Q = X * transpose(Wq);
    Matrix K = X * transpose(Wk);
    Matrix V = X * transpose(Wv);

    Matrix AttentionPattern = softmax(Q * transpose(K));

    Matrix out = AttentionPattern * V;

    return out; 
  }

};
