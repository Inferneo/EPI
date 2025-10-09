// Implement Even-Odd Merge

#include <array>
#include <memory>

using std::array;
using std::make_shared;
using std::shared_ptr;

template <typename T> struct ListNode {
  T data{};
  shared_ptr<ListNode<T>> next{nullptr};
};

shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>> &L) {
  if (L == nullptr) {
    return L;
  }
  auto even_dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
  auto odd_dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, nullptr});
  array<shared_ptr<ListNode<int>>, 2> tails = {even_dummy_head, odd_dummy_head};
  int turn = 0;
  for (auto iter = L; iter; iter = iter->next) {
    tails[turn]->next = iter;
    tails[turn] = tails[turn]->next;
    turn ^= 1; // Alternates between even and odd.
  }
  tails[1]->next = nullptr;
  tails[0]->next = odd_dummy_head->next;
  return even_dummy_head->next;
}