// Merge Sorted Files

#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

using std::cout;
using std::greater;
using std::next;
using std::priority_queue;
using std::vector;

struct IteratorCurrentAndEnd {
  bool operator>(const IteratorCurrentAndEnd &that) const {
    return *current > *that.current;
  }

  vector<int>::const_iterator current;
  vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>> &sorted_arrays) {
  priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>,
                 greater<>>
      min_heap;

  for (const vector<int> &sorted_array : sorted_arrays) {
    if (!sorted_array.empty()) {
      min_heap.emplace(
          IteratorCurrentAndEnd{sorted_array.cbegin(), sorted_array.cend()});
    }
  }

  vector<int> result;
  while (!min_heap.empty()) {
    auto smallest_array = min_heap.top();
    min_heap.pop();
    if (smallest_array.current != smallest_array.end) {
      result.emplace_back(*smallest_array.current);
      min_heap.emplace(IteratorCurrentAndEnd{next(smallest_array.current),
                                             smallest_array.end});
    }
  }
  return result;
}

int main() {
  vector<int> v{2, 3, 4, 5, 6};
  vector<int> v_2{8, 30, 41, 220, 605};
  vector<int> v_3{5, 11, 20, 33, 54};
  vector<vector<int>> v_sort{v, v_2, v_3};

  auto v_final = MergeSortedArrays(v_sort);

  for (auto x : v_final) {
    cout << x << " ";
  }
  cout << '\n';
}