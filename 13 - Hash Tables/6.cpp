// Find the Nearest Repeated Entries in an Array

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::min;
using std::string;
using std::unordered_map;
using std::vector;

int FindNearestRepetition(const vector<string> &paragraph) {
  unordered_map<string, int> word_to_latest_index;
  int nearest_repeated_distance = std::numeric_limits<int>::max();
  for (int i = 0; i < paragraph.size(); ++i) {
    auto latest_equal_word = word_to_latest_index.find(paragraph[i]);
    if (latest_equal_word != word_to_latest_index.end()) {
      nearest_repeated_distance =
          min(nearest_repeated_distance, i - latest_equal_word->second);
    }
    word_to_latest_index[paragraph[i]] = i;
  }
  return nearest_repeated_distance;
}

int main() {
  vector<string> v{
      "void",   "ash",      "mirror", "void",    "silence", "ember",  "ash",
      "pulse",  "grave",    "void",   "hollow",  "scar",    "ember",  "echo",
      "storm",  "mirror",   "decay",  "phantom", "void",    "relic",  "specter",
      "ash",    "ruin",     "veil",   "cinder",  "storm",   "stone",  "dream",
      "fume",   "tomb",     "void",   "glare",   "serpent", "thorn",  "glass",
      "ash",    "smoke",    "torch",  "flesh",   "void",    "maw",    "vessel",
      "plague", "seraph",   "iron",   "noise",   "crypt",   "lust",   "mirror",
      "sorrow", "phantasm", "haze",   "root",    "void",    "aether", "dusk",
      "core",   "silt",     "groan",  "blade",   "husk",    "skin",   "idol",
      "marrow", "ash",      "gloom",  "void",    "storm",   "echo",   "dream",
      "thorn",  "cinder",   "scar",   "ruin"};

  cout << FindNearestRepetition(v) << '\n';
}