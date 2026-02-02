#include <iostream>
#include "matrix.hpp"
#include "random.hpp"
#include "ReLU.hpp"

using namespace std;

int main() {
  Matrix a(10, 5);

  auto print = [&](Matrix x) {
    for(int i = 0; i < x.rows; i++) {
      for(int j = 0; j < x.cols; j++) {
        cout << x(i, j) << " \n"[j == x.cols - 1];
      }
    }
    cout << endl;
  };

  print(a);

  a.randomize();

  print(a);

  a = ReLU(a);

  print(a);

  return 0;
}
