// Generate Permutations

#include <algorithm>
#include <utility>
#include <vector>

using std::next_permutation;
using std::sort;
using std::swap;
using std::vector;

void DirectedPermutations(int i, vector<int> *A_ptr,
                          vector<vector<int>> *result) {
  vector<int> &A = *A_ptr;
  if (i == A.size() - 1) {
    result->emplace_back(A);
    return;
  }

  // Try every possibility for A[i].
  for (int j = i; j < A.size(); ++j) {
    swap(A[i], A[j]);
    // Generate all permutations for A[i + 1 : A.size() - 1].
    DirectedPermutations(i + 1, A_ptr, result);
    swap(A[i], A[j]);
  }
}

vector<vector<int>> Permutations(vector<int> A) {
  vector<vector<int>> result;
  DirectedPermutations(0, &A, &result);
  return result;
}

vector<vector<int>> Permutations2(vector<int> A) {
  vector<vector<int>> result;
  // Generate the first permutation in dictionary order.
  sort(A.begin(), A.end());
  do {
    result.emplace_back(A);
  } while (next_permutation(A.begin(), A.end()));
  return result;
}