// Search a Sorted Array for First Occurrence of k

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int SearchFirstOfK(const vector<int> &A, int k) {

  int left = 0, right = A.size() - 1, result = -1;
  // [left:right] is the candidate set.
  while (left <= right) {
    int mid = left + ((right - left) / 2);
    if (A[mid] > k) {
      right = mid - 1;
    } else if (A[mid] == k) {
      result = mid;
      // Nothing to the right of mid can be the first occurrence of k.
      right = mid - 1;
    } else { // A[mid] < k
      left = mid + 1;
    }
  }
  return result;

}

int main() {

  vector<int> v_firstk = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};

  cout << SearchFirstOfK(v_firstk, 0) << '\n';
}