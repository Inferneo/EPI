// Sample Offline Data

#include <iostream>
#include <random>
#include <utility>
#include <vector>

using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

void RandomSampling(int k, vector<int> *A_ptr) {
  vector<int> &A = *A_ptr;
  default_random_engine seed((random_device())()); // Random num generator
  for (int i = 0; i < k; ++i) {
    // Generate a random index in [i, A.size()-1].
    std::swap(A[i], A[uniform_int_distribution<int>{
                        i, static_cast<int>(A.size() - 1)}(seed)]);
  }
}

int main() {
  vector<int> v = {4, 6, 1, 40, 22, 10};
  RandomSampling(3, &v);
  for (auto x : v) {
    std::cout << x << '\t';
  }
  std::cout << '\n';
}