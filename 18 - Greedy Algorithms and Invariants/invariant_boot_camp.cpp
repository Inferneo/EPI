// Two-Sum Problem

#include <vector>

using std::vector;

bool HasTwoSum(const vector<int> &A, int t) {
  int i = 0, j = A.size() - 1;
  while (i <= j) {
    if (A[i] + A[j] == t) {
      return true;
    } else if (A[i] + A[j] < t) {
      ++i;
    } else { // A[i] + A[j] > t
      --j;
    }
  }
  return false;
}