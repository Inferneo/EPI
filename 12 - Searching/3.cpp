// Search a Cyclically Sorted Array

#include <vector>
using std::vector;

int SearchSmallest(const vector<int> &A) {
  int left = 0, right = A.size() - 1;
  while (left < right) {
    int mid = left + ((right - left) / 2);
    if (A[mid] > A[right]) {
      // Minimum must be in [mid + 1 : right].
      left = mid + 1;
    } else {
      // Minimum cannot be in [mid + 1 : right] so it must be in [left : mid].
      right = mid;
    }
  }
  // Loop ends when left == right.
  return left;
}