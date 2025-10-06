// Find the kth Largest Element

#include <functional>
#include <iostream>
#include <random>
#include <stdexcept>
#include <utility>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::greater;
using std::logic_error;
using std::out_of_range;
using std::random_device;
using std::swap;
using std::uniform_int_distribution;
using std::vector;

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.

// Partition A[left : right] around pivot_idx, returns the new index of the
// pivot, new_pivot_idx, after partition. After partitioning, A[left :
// new_pivot_idx - 1] contains elements that are greater than the pivot, and
// A[new_pivot_idx + 1 : right] contains elements that are less than the pivot.
//
// Note : "less than" is defined by the Compare object.
//
// Returns the new index of the pivot element after partition.
template <typename Compare>
int PartitionAroundPivot(int left, int right, int pivot_idx, Compare comp,
                         vector<int> *A_ptr) {
  vector<int> &A = *A_ptr;
  int pivot_value = A[pivot_idx];
  int new_pivot_idx = left;
  swap(A[pivot_idx], right);
  for (int i = left; i < right; ++i) {
    if (comp(A[i], pivot_value)) {
      swap(A[i], A[new_pivot_idx++]);
    }
  }
  swap(A[right], A[new_pivot_idx]);
  return new_pivot_idx;
}

template <typename Compare>
int FindKth(int k, Compare comp, vector<int> *A_ptr) {
  vector<int> &A = *A_ptr;
  int left = 0, right = A.size() - 1;
  default_random_engine gen((random_device())());
  if (k < 1 || (k > static_cast<int>(A.size()))) {
    throw out_of_range("k out of range");
  }
  while (left <= right) {
    // Generates a random integer in [left, right].
    int pivot_idx = uniform_int_distribution<int>{left, right}(gen);
    int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, comp, &A);
    if (new_pivot_idx == k - 1) {
      return A[new_pivot_idx];
    } else if (new_pivot_idx > k - 1) {
      right = new_pivot_idx - 1;
    } else { // new_pivot_idx < k - 1.
      left = new_pivot_idx + 1;
    }
  }
  throw logic_error("Find Kth: algorithm failed.");
}

int FindKthLargest(int k, vector<int> *A_ptr) {
  return FindKth(k, greater<int>(), A_ptr);
}

int main() {
  vector<int> v = {41, 20, 3, 10, 703, 22, 30};

  cout << FindKthLargest(2, &v) << '\n';
}