#include <memory>

using std::unique_ptr;

template <typename T> struct BSTNode {
  T data;
  unique_ptr<BSTNode<T>> left, right;
};

BSTNode<int> *SearchBST(const unique_ptr<BSTNode<int>> &tree, int key) {
  if (tree == nullptr) {
    return nullptr;
  }
  if (tree->data == key) {
    return tree.get();
  }

  return key < tree->data ? SearchBST(tree->left, key)
                          : SearchBST(tree->right, key);
}