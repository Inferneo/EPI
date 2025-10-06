// Test if a Binary Tree Satisfies the BST Property

#include <limits>
#include <memory>
#include <queue>

using std::numeric_limits;
using std::queue;
using std::unique_ptr;

template <typename T> struct BinaryTreeNode {
  T data{};
  unique_ptr<BinaryTreeNode<T>> left{nullptr}, right{nullptr};
};

bool AreKeysInRange(const unique_ptr<BinaryTreeNode<int>> &tree, int low_range,
                    int high_range) {
  if (tree == nullptr) {
    return true;
  } else if (tree->data < low_range || high_range < tree->data) {
    return false;
  }

  return AreKeysInRange(tree->left, low_range, tree->data) &&
         AreKeysInRange(tree->right, tree->data, high_range);
}

bool IsBinaryTreeBST_DFS(const unique_ptr<BinaryTreeNode<int>> &tree) {
  return AreKeysInRange(tree, numeric_limits<int>::min(),
                        numeric_limits<int>::max());
}

struct QueueEntry {
  const unique_ptr<BinaryTreeNode<int>> &tree_node;
  int lower_bound, upper_bound;
};

bool IsBinaryTreeBST_BFS(const unique_ptr<BinaryTreeNode<int>> &tree) {
  queue<QueueEntry> BFS_queue;
  BFS_queue.emplace(
      QueueEntry{tree, numeric_limits<int>::min(), numeric_limits<int>::max()});

  while (!BFS_queue.empty()) {
    if (BFS_queue.front().tree_node.get()) {
      if (BFS_queue.front().tree_node->data < BFS_queue.front().lower_bound ||
          BFS_queue.front().upper_bound < BFS_queue.front().tree_node->data) {
        return false;
      }

      BFS_queue.emplace(QueueEntry{BFS_queue.front().tree_node->left,
                                   BFS_queue.front().lower_bound,
                                   BFS_queue.front().tree_node->data});
      BFS_queue.emplace(QueueEntry{BFS_queue.front().tree_node->right,
                                   BFS_queue.front().tree_node->data,
                                   BFS_queue.front().upper_bound});
    }
    BFS_queue.pop();
  }
  return true;
}
