#include "random.hpp"

#include <random>
#include <chrono>

static std::mt19937 rng(
  static_cast<unsigned>(
    std::chrono::steady_clock::now().time_since_epoch().count()
  )
);
 
int randomInt(int l, int r) {
  std::uniform_int_distribution<int> dist(l, r);
	return dist(rng);
}

double randomFloat(double l, double r) {
  std::uniform_real_distribution<double> dist(l, r);
  return dist(rng);
}
