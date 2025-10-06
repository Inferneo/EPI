// Replace and Remove

#include <iostream>
int ReplaceAndRemove(int size, char s[]) {
  // Forward Iteration: remove "b"s and count the number of "a"s.
  int write_idx = 0, a_count = 0;
  for (int i = 0; i < size; ++i) {
    if (s[i] != 'b') {
      s[write_idx++] = s[i];
    }
    if (s[i] == 'a') {
      ++a_count;
    }
  }
  // Backward Iteration: replace "a"s with "dd"s starting from the end.
  int cur_idx = write_idx - 1;
  write_idx = write_idx + a_count - 1;
  const int final_size = write_idx + 1;
  while (cur_idx >= 0) {
    if (s[cur_idx] == 'a') {
      s[write_idx--] = 'd';
      s[write_idx--] = 'd';
    } else {
      s[write_idx--] = s[cur_idx];
    }
    --cur_idx;
  }
  return final_size;
}

int main() {
    char word[] = {'a', 's', 'v', 'd', 'b'};

    std::cout << ReplaceAndRemove(77, word) << '\n';
}