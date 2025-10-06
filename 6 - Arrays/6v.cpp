// Longest Subarray of Equals

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using std::max;
using std::vector;

int LargestEqualSubArray(const vector<int> &equals) {
  int max_arr = 1;
  int max_current = 1;
  for (size_t i = 1; i < equals.size(); ++i) {
    int diff = equals[i] - equals[i - 1];
    if (diff == 0) {
      ++max_current;
    } else {
      max_current = 1;
    }
    max_arr = max(max_current, max_arr);
  }
  return max_arr;
}

int main() {
  vector<int> Equals = {310, 311, 211, 275, 210, 210, 210, 230};

  std::cout << LargestEqualSubArray(Equals) << '\n';
}