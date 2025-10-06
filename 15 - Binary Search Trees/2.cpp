// Find the First Key Greater Than a Given Value in a BST

#include <memory>

using std::unique_ptr;

template <typename T> struct BSTNode {
  T data{};
  unique_ptr<BSTNode<T>> left{nullptr}, right{nullptr};
};

BSTNode<int> *FindFirstGreaterThanK(const unique_ptr<BSTNode<int>> &tree,
                                    int k) {
  BSTNode<int> *subtree = tree.get(), *first_so_far = nullptr;
  while (subtree) {
    if (subtree->data > k) {
      first_so_far = subtree;
      subtree = subtree->left.get();
    } else { // Root and all keys in left subtree are <= k, so skip them.
      subtree = subtree->right.get();
    }
  }
  return first_so_far;
}