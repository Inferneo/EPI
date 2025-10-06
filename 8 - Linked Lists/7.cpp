// Remove the Kth Last Element From a List

#include <memory>

using std::make_shared;
using std::shared_ptr;

template <typename T> struct ListNode {
  T data{};
  shared_ptr<ListNode<T>> next{nullptr};
};

// Assumes L has at least k nodes, deletes the k-th last node in L.
shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>> &L,
                                        int k) {
  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto first = dummy_head->next;
  while (k--) {
    first = first->next;
  }

  auto second = dummy_head;
  while (first) {
    second = second->next, first = first->next;
  }

  // second points to the (k+1)-th last node, deletes its successor.
  second->next = second->next->next;
  return dummy_head->next;
}