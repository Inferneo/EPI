// Delete Duplicates From a Sorted Array

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int DeleteDuplicates(vector<int> *A_ptr) {
  vector<int> &A = *A_ptr;
  if (A.empty()) {
    return 0;
  }

  int write_index = 1;
  for (int i = 0; i < A.size(); ++i) {
    if (A[write_index - 1] != A[i]) {
      A[write_index++] = A[i];
    }
  }
  return write_index;
}

int main() {
  vector<int> v{2, 3, 5, 5, 7, 11, 11, 11, 13};
  auto r = DeleteDuplicates(&v);
  cout << r << '\n';
}