// Compute the Successor

#include <memory>

using std::unique_ptr;

template <typename T> struct BinaryTreeNode {
  T data{};
  unique_ptr<BinaryTreeNode<T>> left{nullptr}, right{nullptr};
  BinaryTreeNode<T> *parent;
};

BinaryTreeNode<int> *
FindSuccessor(const unique_ptr<BinaryTreeNode<int>> &node) {
  auto iter = node.get();
  if (iter->right != nullptr) {
    // Successor is the leftmost element in node's right subtree.
    iter = iter->right.get();
    while (iter->left) {
      iter = iter->left.get();
    }
    return iter;
  }

  // Find the closest ancestor whose left subtree contains node.
  while (iter->parent != nullptr && iter->parent->right.get() == iter) {
    iter = iter->parent;
  }
  // A return value of nullptr means node does not have a successor, i.e., it is
  // the rightmost node in the tree.
  return iter->parent;
}

// Number of edges followed cannot be greater than the tree height, time
// complexity O(h).