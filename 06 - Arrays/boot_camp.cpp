#include <iostream>
#include <utility>
#include <vector>

using std::vector;

void EvenOdd(vector<int> *A_ptr) {
  vector<int> &A = *A_ptr;
  if (A.empty()) {
    return;
  }
  auto even = A.begin();
  auto odd = A.end() - 1;
  while (even < odd) {
    if ((*even) % 2) {
      std::swap(*even, *odd);
      --odd;
    } else {
      ++even;
    }
  }
}

int main() {
  vector<int> v{3, 5, 2, 1, 4};
  EvenOdd(&v);
  for (auto x : v) {
    std::cout << x << '\t';
  }
  std::cout << '\n';
}