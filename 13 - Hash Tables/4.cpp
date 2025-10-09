// Compute the LCA, Optimizing for Close Ancestors

#include <bits/stdc++.h>

using namespace std;

template <typename T> struct BinaryTreeNode {
  T data{};
  unique_ptr<BinaryTreeNode<T>> left{nullptr}, right{nullptr};
  BinaryTreeNode<T> *parent;
};

BinaryTreeNode<int> *LCA(const unique_ptr<BinaryTreeNode<int>> &node_0,
                         const unique_ptr<BinaryTreeNode<int>> &node_1) {
  auto *iter_0 = node_0.get(), *iter_1 = node_1.get();
  unordered_set<const BinaryTreeNode<int> *> nodes_on_path_to_root;
  while (iter_0 || iter_1) {
    // Ascend tree in tandem for these two nodes.
    if (iter_0) {
      if (nodes_on_path_to_root.emplace(iter_0).second == false) {
        return iter_0;
      }
      iter_0 = iter_0->parent;
    }
    if (iter_1) {
      if (nodes_on_path_to_root.emplace(iter_1).second == false) {
        return iter_1;
      }
      iter_1 = iter_1->parent;
    }
  }
  throw invalid_argument("node_0 and node_1 are not in the same tree.");
}

// O(D0 + D1) space and time. D0 and D1 are the spaces from the LCA to node_0
// and node_1 respectively.