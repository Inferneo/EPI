// Implement a Fast Sorting Algorithm for Lists

#include <memory>

using std::make_shared;
using std::shared_ptr;

template <typename T> struct ListNode {
  T data{};
  shared_ptr<ListNode<T>> next{nullptr};
};

shared_ptr<ListNode<int>> InsertionSort(const shared_ptr<ListNode<int>> &L) {
  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto iter = L;

  // The sublist consisting of nodes up to and including iter is sorted in
  // increasing order. We need to ensure that after we move to iter->next this
  // property continues to hold. We do this by swapping iter->next with its
  // predecessors in the list till it's in the right place.
  while (iter && iter->next) {
    if (iter->data > iter->next->data) {
      auto target = iter->next, pre = dummy_head;
      while (pre->next->data < target->data) {
        pre = pre->next;
      }
      auto temp = pre->next;
      pre->next = target;
      iter->next = target->next;
      target->next = temp;
    } else {
      iter = iter->next;
    }
  }
  return dummy_head->next;
}

// Time complexity O(n^2) when list is reverse sorted to begin with. Space is
// O(1).

