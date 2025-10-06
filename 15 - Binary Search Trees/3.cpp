// Find the k largest elements in a BST

#include <memory>
#include <vector>
using std::unique_ptr;
using std::vector;

template <typename T> struct BSTNode {
  T data{};
  unique_ptr<BSTNode<T>> left{nullptr}, right{nullptr};
};

void FindKLargestInBSTHelper(const unique_ptr<BSTNode<int>> &tree, int k,
                             vector<int> *k_largest_elements) {
  // Perform reverse in-order traversal.
  if (tree && k_largest_elements->size() < k) {
    FindKLargestInBSTHelper(tree->right, k, k_largest_elements);
  }
  if (k_largest_elements->size() < k) {
    k_largest_elements->emplace_back(tree->data);
    FindKLargestInBSTHelper(tree->left, k, k_largest_elements);
  }
}

vector<int> FindKLargestinBST(const unique_ptr<BSTNode<int>> &tree, int k) {
  vector<int> k_largest_elements;
  FindKLargestInBSTHelper(tree, k, &k_largest_elements);
  return k_largest_elements;
}
