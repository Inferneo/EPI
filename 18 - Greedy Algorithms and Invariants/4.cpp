// The 3-Sum Problem

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

bool HasTwoSum(const vector<int> &A, int t) {
  int i = 0, j = A.size() - 1;
  while (i <= j) {
    if (A[i] + A[j] == t) {
      return true;
    } else if (A[i] + A[j] < t) {
      ++i;
    } else {
      --j;
    }
  }
  return false;
}

bool HasThreeSum(vector<int> &A, int t) {
  sort(A.begin(), A.end());

  for (int a : A) {
    // Finds if the sum of two numbers in A equals to t - a.
    if (HasTwoSum(A, t - a)) {
      return true;
    }
  }
  return false;
}