// Compute the LCA in a BST

#include <memory>

using std::unique_ptr;

template <typename T> struct BSTNode {
  T data{};
  unique_ptr<BSTNode<T>> left{nullptr}, right{nullptr};
};

BSTNode<int> *FindLCA(const unique_ptr<BSTNode<int>> &tree,
                      const unique_ptr<BSTNode<int>> &s,
                      const unique_ptr<BSTNode<int>> &b) {
  auto *p = tree.get();
  while (p->data < s->data || p->data > b->data) {
    // Keep searching since p is outside of [s, b].
    while (p->data < s->data) {
      p = p->right.get(); // LCA must be in p's right child.
    }
    while (p->data > b->data) {
      p = p->left.get(); // LCA must be in p's left child.
    }
  }
  // Now, s->data <= p->data && p->data <= b->data.
  return p;
}
