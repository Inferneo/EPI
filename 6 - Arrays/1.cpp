// The Dutch National Flag Problem

#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::swap;
using std::vector;

typedef enum { RED, WHITE, BLUE } Color;

void DutchFlagPartition(int pivot_index, vector<Color> *A_ptr) {
  vector<Color>& A = *A_ptr;
  Color pivot = A[pivot_index];
  int smaller = 0;
  // First pass: Group elements smaller than pivot
  for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] < pivot) {
          swap(A[i], A[smaller++]);
          break;
        }
    }
  // Second pass: Group elements larger than pivot
  int larger = A.size() - 1;
  for (int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i) {
        if (A[i] > pivot) {
          swap(A[i], A[larger--]);
          break;
        }
    }
}

void DutchFlagPartition2(int pivot_index, vector<Color> *A_ptr) {
    vector<Color>& A = *A_ptr;
    if (A.empty()) {
        return;
    }
    Color pivot = A[pivot_index];
    int smaller = 0, equal = 0, larger = int(A.size()) - 1;
    while (equal < larger) {
        if (A[equal] < pivot) {
          swap(A[smaller++], A[equal++]);
        }
        else if (A[equal] == pivot) {
            ++equal;
        }
        else { // A[equal] > pivot
          swap(A[equal++], A[larger--]);
        }
    } 
}

int main() {
    vector<Color> V_Color 
    {Color(0), Color(1), Color(2), Color(0), Color(1), Color(0)};
    auto V_ptr = &V_Color;
    DutchFlagPartition(2, V_ptr);
    for (auto x : V_Color) {
      cout << x << '\t';
    }
    cout << '\n';
}
