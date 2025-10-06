#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;

int bin_search(int k, vector<int> &A) {
  int first = 0;
  int last = static_cast<int>(A.size()) - 1;
  while (first <= last) {
    int M = (first + (last - first)) / 2;
    if (A[M] < k) {
      first = M + 1;
    } else if (k < A[M]) {
      last = M - 1;
    }
    else {
        return M;
    }
  }
  return -1;
}

int main() {
    vector<int> v = {3, 11, 40, 271, 290};
    auto f = bin_search(271, v);

    std::cout << f << '\n';
}