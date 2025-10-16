// Build A Minimum Height BST From A Sorted Array

#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

template <typename T> struct BSTNode {
  T data{};
  unique_ptr<BSTNode<int>> left{nullptr}, right{nullptr};
};

// Build a min-height BST over the entries in A[start : end - 1].
unique_ptr<BSTNode<int>>
BuildMinHeightBSTFromSortedArrayHelper(const vector<int> &A, int start,
                                       int end) {
  if (start >= end) {
    return nullptr;
  }
  int mid = start + ((end - start) / 2);
  return make_unique<BSTNode<int>>(BSTNode<int>{
      A[mid], BuildMinHeightBSTFromSortedArrayHelper(A, start, mid),
      BuildMinHeightBSTFromSortedArrayHelper(A, mid + 1, end)});
}

unique_ptr<BSTNode<int>>
BuildMinHeightBSTFromSortedArray(const vector<int> &A) {
  return BuildMinHeightBSTFromSortedArrayHelper(A, 0, A.size());
}

// Time complexity is O(n). (n calls to the recursive function, O(1) within each
// call)