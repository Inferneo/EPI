// Tests for Overlapping Lists - Lists are Cycle-Free

#include <cstdlib>
#include <memory>

using std::abs;
using std::shared_ptr;

template <typename T> struct ListNode {
  T data{};
  shared_ptr<ListNode<T>> next{nullptr};
};

int Length(shared_ptr<ListNode<int>> L) {
  int length = 0;
  while (L) {
    ++length, L = L->next;
  }
  return length;
}

// Advances L by K steps
void AdvanceListByK(int k, shared_ptr<ListNode<int>> *L) {
  while (k--) {
    *L = (*L)->next;
  }
}

shared_ptr<ListNode<int>>
OverlappingNoCycleLists(shared_ptr<ListNode<int>> L1,
                        shared_ptr<ListNode<int>> L2) {
  int L1_len = Length(L1), L2_len = Length(L2);

  // Advances the longer list to get equal length lists.
  AdvanceListByK(abs(L1_len - L2_len), L1_len > L2_len ? &L1 : &L2);

  while (L1 && L2 && L1 != L2) {
    L1 = L1->next, L2 = L2->next;
  }
  return L1; // nullptr implies there is no overlap between L1 and L2.
}
