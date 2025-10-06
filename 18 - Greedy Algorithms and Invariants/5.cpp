// Find the Majority Element

#include <sstream>
#include <string>

using std::istringstream;
using std::string;

string MajoritySearch(istringstream *input_stream) {
  string candidate, iter;
  int candidate_count = 0;
  while (*input_stream >> iter) {
    if (candidate_count == 0) {
      candidate = iter;
      candidate_count = 1;
    } else if (candidate == iter) {
      ++candidate_count;
    } else {
      --candidate_count;
    }
  }
  return candidate;
}