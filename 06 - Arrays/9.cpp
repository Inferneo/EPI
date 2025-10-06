// Permute the Elements of an Array

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::for_each;
using std::swap;
using std::vector;

void ApplyPermutation(vector<int> *A_ptr, vector<int> *perm_ptr) {
  vector<int> &perm = *perm_ptr, &A = *A_ptr;
  for (int i = 0; i < A.size(); ++i) {
    // Check if the element at index i has not been moved by checking if perm[i]
    // is non-negative
    int next = i;
    while (perm[next] >= 0) {
      swap(A[i], A[perm[next]]);
      int temp = perm[next];
      // Subtracts perm.size() from an entry in perm to make it negative, which
      // indicates that the corresponding move has been performed.
      perm[next] -= perm.size();
      next = temp;
    }
  }

  // Restore perm.
  for_each(perm.begin(), perm.end(), [&](int &x) { x += perm.size(); });
}

void CyclicPermutation(int start, const vector<int>& perm, vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;
    int i = start;
    int temp = A[start];
    do {
    int next_i = perm[i];
    int next_temp = A[next_i];
    A[next_i] = temp;
    i = next_i, temp = next_temp;
    }while (i != start);
}

void ApplyPermutation2(const vector<int>& perm, vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;
    for (int i = 0; i < A.size(); ++i) {
        // Traverses the cycle to see if i is the minimum element.
        bool is_min = true;
        int j = perm[i];
        while (j != i) {
            if (j < i) {
                is_min = false;
                break;
            }
            j = perm[j];
        }
        if (is_min) {
            CyclicPermutation(i, perm, &A);
        }
    }
}

int main() {
  vector<int> A = {30, 10, 20, 40};
  vector<int> perm = {3, 0, 1, 2};

  for (auto x : A) {
    cout << x << '\t';
  }
  cout << '\n';
  ApplyPermutation(&A, &perm);

  for (auto x : perm) {
    cout << x << '\t';
  }
  cout << '\n';
  for (auto x : A) {
    cout << x << '\t';
  }
  cout << '\n';
}