// Sort an Almost-Sorted Array

#include <functional>
#include <iostream>
#include <ostream>
#include <queue>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::greater;
using std::istringstream;
using std::priority_queue;
using std::vector;

void SortApproximatelySortedData(istringstream *sequence, int k) {
  priority_queue<int, vector<int>, greater<>> min_heap;
  
  // Adds the first k elements into min_heap. Stop if there are fewer than k
  // elements.
  int x;
  for (int i = 0; i < k && *sequence >> x; ++i) {
    min_heap.push(x);
  }

  // For every new element, add it to min_heap and extract the smallest.
  while (*sequence >> x) {
    min_heap.push(x);
    cout << min_heap.top() << endl;
    min_heap.pop();
  }

  // sequence is exhausted, iteratively extracts the remaining elements.
  while (!min_heap.empty()) {
    cout << min_heap.top() << endl;
    min_heap.pop();
  }
}