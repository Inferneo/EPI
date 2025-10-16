// Reconstruct a BST from Traversal Data

#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

template <typename T> struct BSTNode {
  T data{};
  unique_ptr<BSTNode<T>> left{nullptr}, right{nullptr};
};

// Rebuilds a BST from preorder_sequence[start : end - 1].
unique_ptr<BSTNode<int>>
RebuildBSTFromPreorderHelper(const vector<int> &preorder_sequence, int start,
                             int end) {
  if (start >= end) {
    return nullptr;
  }
  int transition_point = start + 1;
  while (transition_point < end &&
         preorder_sequence[transition_point] < preorder_sequence[start]) {
    ++transition_point;
  }
  return make_unique<BSTNode<int>>(BSTNode<int>{
      preorder_sequence[start],
      RebuildBSTFromPreorderHelper(preorder_sequence, start + 1,
                                   transition_point),
      RebuildBSTFromPreorderHelper(preorder_sequence, transition_point, end)});
}

unique_ptr<BSTNode<int>>
RebuildBSTFromPreorder(const vector<int> &preorder_sequence) {
  return RebuildBSTFromPreorderHelper(preorder_sequence, 0,
                                      preorder_sequence.size());
}
