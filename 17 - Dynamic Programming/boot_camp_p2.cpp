// Maximum Sum Over All Sub-Arrays

#include <vector>

using std::vector;

int FindMaximumSubArray(const vector<int> &A) {
  int min_sum = 0, sum = 0, max_sum = 0;
  for (int i = 0; i < A.size(); ++i) {
    sum += A[i];
    if (sum < min_sum) {
      min_sum = sum;
    }
    if (sum - min_sum > max_sum) {
      max_sum = sum - min_sum;
    }
  }
  return max_sum;
}