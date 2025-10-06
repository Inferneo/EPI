// Increment an Arbitrary-Precision Integer

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int> PlusOne(vector<int> A) {
  ++A.back();
  for (int i = A.size() - 1; i > 0 && A[i] == 10; --i) {
    A[i] = 0, ++A[i - 1];
  }
  if (A[0] == 10) {
    // Need additional digit as the most significant digit (i.e. A[0]) has a
    // carry-out.
    A[0] = 0;
    A.insert(A.begin(), 1);
  }
  return A;
}

int main() {
  vector<int> v{9, 9, 9};
  auto v2 = PlusOne(v);
  for (auto x : v2) {
    cout << x << " ";
  }
  cout << '\n';
}