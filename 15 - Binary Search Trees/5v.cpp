#include <limits>
#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

template <typename T> struct BSTNode {
  T data{};
  unique_ptr<BSTNode<T>> left{nullptr}, right{nullptr};
};

// Builds a BST on the subtree rooted at root_idx from preorder_sequence on keys
// in (lower_bound, upper_bound).
unique_ptr<BSTNode<int>>
RebuildBSTFromPreorderOnValueRange(const vector<int> &preorder_sequence,
                                   int lower_bound, int upper_bound,
                                   int *root_idx_ptr) {
  int &root_idx = *root_idx_ptr;
  if (root_idx == preorder_sequence.size()) {
    return nullptr;
  }

  int root = preorder_sequence[root_idx];
  if (root < lower_bound || root > upper_bound) {
    return nullptr;
  }
  ++root_idx;
  // Note that RebuildBSTFromPreorderOnValueRange updates root_idx. So the order
  // of following two calls are critical.
  auto left_subtree = RebuildBSTFromPreorderOnValueRange(
      preorder_sequence, lower_bound, root, root_idx_ptr);
  auto right_subtree = RebuildBSTFromPreorderOnValueRange(
      preorder_sequence, root, upper_bound, root_idx_ptr);
  return make_unique<BSTNode<int>>(
      BSTNode<int>{root, std::move(left_subtree), std::move(right_subtree)});
}

unique_ptr<BSTNode<int>>
RebuildBSTFromPreorder(const vector<int> &preorder_sequence) {
  int root_idx = 0;
  return RebuildBSTFromPreorderOnValueRange(
      preorder_sequence, std::numeric_limits<int>::min(),
      std::numeric_limits<int>::max(), &root_idx);
}

// Time complexity is O(n), constant amount of work per node. 