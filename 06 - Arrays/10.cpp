// Compute the Next Permutation

#include <algorithm>
#include <utility>
#include <vector>

using std::find_if;
using std::reverse;
using std::swap;
using std::vector;

vector<int> NextPermutation(vector<int> perm) {
  int k = perm.size() - 2;
  while (k >= 0 && perm[k] >= perm[k + 1]) {
    --k;
  }
  if (k == -1) {
    return {}; // perm is the last permutation.
  }

  // Swap the smallest entry after index k that is greater than perm[k]. We
  // exploit the fact that perm[k + 1 : perm.size() - 1] is decreasing so if we
  // search in reverse order, the first entry that is greater than perm[k] is
  // the smallest such entry.
  swap(*find_if(perm.rbegin(), perm.rend(), [&](int a) { return a > perm[k]; }),
       perm[k]);

  // Since perm[k + 1 : perm.size() - 1] is in decreasing order, we can build
  // the smallest dictionary ordering of this subarray by reversing it.
  reverse(perm.begin() + k + 1, perm.end());
  return perm;
}