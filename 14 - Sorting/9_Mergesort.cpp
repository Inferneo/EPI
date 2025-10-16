// Mergesort on Lists

#include <memory>

using std::make_shared;
using std::shared_ptr;

template <typename T> struct ListNode {
  T data{};
  shared_ptr<ListNode<T>> next{nullptr};
};

void AppendNode(shared_ptr<ListNode<int>> *node,
                shared_ptr<ListNode<int>> *tail) {
  (*tail)->next = *node;
  *tail = *node; // Updates tail.
  *node = (*node)->next;
}

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // Creates a placeholder for the result.
  auto dummy_head = make_shared<ListNode<int>>();
  auto tail = dummy_head;

  while (L1 && L2) {
    AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
  }

  // Appends the remaining nodes of L1 or L2
  tail->next = L1 ? L1 : L2;
  return dummy_head->next;
}

shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> L) {
  // Base cases: L is empty or a single node, nothing to do.
  if (L == nullptr || L->next == nullptr) {
    return L;
  }

  // Find the midpoint of L using a fast and a slow pointer.
  shared_ptr<ListNode<int>> pre_slow = nullptr, slow = L, fast = L;
  while (fast && fast->next) {
    pre_slow = slow;
    fast = fast->next->next, slow = slow->next;
  }

  pre_slow->next = nullptr; // Splits the list into two equal-sized lists.

  return MergeTwoSortedLists(StableSortList(L), StableSortList(slow));
}