// Compute the Median of Online Data

#include <functional>
#include <iostream>
#include <ostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

void OnlineMedian(istringstream *sequence) {
  // min_heap stores the larger half seen so far.
  priority_queue<int, vector<int>, greater<>> min_heap;
  // max_heap stores the smaller half seen so far.
  priority_queue<int, vector<int>, less<>> max_heap;

  int x;
  while (*sequence >> x) {
    if (min_heap.empty()) {
      // This is the very first element.
      min_heap.emplace(x);
    } else {
      if (x >= min_heap.top()) {
        min_heap.emplace(x);
      } else {
        max_heap.emplace(x);
      }
    }
    // Ensure min_heap and max_heap have an equal number of elements if an even
    // number of elements is read; otherwise, min_heap must have one more
    // element than max_heap.
    if (min_heap.size() > max_heap.size() + 1) {
      max_heap.emplace(min_heap.top());
      min_heap.pop();
    } else if (max_heap.size() > min_heap.size()) {
      min_heap.emplace(max_heap.top());
      max_heap.pop();
    }
    cout << (min_heap.size() == max_heap.size()
                 ? 0.5 * (min_heap.top() + max_heap.top())
                 : min_heap.top())
         << endl;
  }
}

// Time complexity per entry is O(log n), corresponding to insertion and
// extraction from a heap.