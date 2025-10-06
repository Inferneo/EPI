// Compute the Intersection of Two Sorted Arrays

#include <algorithm>
#include <vector>

using std::binary_search;
using std::vector;

// O(mn) time complexity
vector<int> IntersectTwoSortedArrays_MN(const vector<int> &A,
                                    const vector<int> &B) {
  vector<int> intersection_A_B;
  for (int i = 0; i < A.size(); ++i) {
    if (i == 0 || A[i] != A[i - 1]) {
      for (int b : B) {
        if (A[i] == b) {
          intersection_A_B.emplace_back(A[i]);
          break;
        }
      }
    }
  }
  return intersection_A_B;
}

// O(mlog(n)) time complexity
vector<int> IntersectTwoSortedArrays_mlogn(const vector<int> &A,
                                       const vector<int> &B) {
  vector<int> intersection_A_B;
  for (int i = 0; i < A.size(); ++i) {
    if (i == 0 ||
        A[i] != A[i - 1] && binary_search(B.cbegin(), B.cend(), A[i])) {
      intersection_A_B.emplace_back(A[i]);
    }
  }
  return intersection_A_B;
}

// O(m+n) time complexity
vector<int> IntersectTwoSortedArrays_mplusn(const vector<int> &A,
                                        const vector<int> &B) {
  vector<int> intersection_A_B;
  int i = 0, j = 0;
  while (i < A.size() && j < B.size()) {
    if (A[i] == B[j] && (i == 0 || A[i] != A[i - 1])) {
      intersection_A_B.emplace_back(A[i]);
      ++i, ++j;
    } else if (A[i] < B[j]) {
      ++i;
    } else { // A[i] > B[j]
      ++j;
    }
  }
  return intersection_A_B;
}
