#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::cout;
using std::hash;
using std::string;
using std::unordered_set;
using std::vector;

struct ContactList {
  // Equal function for hash.
  bool operator==(const ContactList &that) const {
    return unordered_set<string>(names.begin(), names.end()) ==
           unordered_set<string>(that.names.begin(), that.names.end());
  }

  vector<string> names;
};

// Hash function for ContactList.
struct HashContactList {
  size_t operator()(const ContactList &contacts) const {
    size_t hash_code = 0;
    for (const string &name :
         unordered_set<string>(contacts.names.begin(), contacts.names.end())) {
      hash_code ^= hash<string>()(name);
    }
    return hash_code;
  }
};

vector<ContactList> MergeContactLists(const vector<ContactList> &contacts) {
  unordered_set<ContactList, HashContactList> unique_contacts(contacts.begin(),
                                                              contacts.end());
  return {unique_contacts.begin(), unique_contacts.end()};
}

int main() {
  ContactList c;
  c.names = {"Behere", "Kane", "Nirantar"};
  ContactList c2;
  c2.names = {"Samnerkar", "Laturkar"};
  ContactList c3;
  c3.names = {"Laturkar", "Samnerkar"};

  vector<ContactList> v_contacts{c, c2, c3};

  auto v_contacts_2 = MergeContactLists(v_contacts);

  int idx = 0;
  for (auto &x : v_contacts_2) {
    cout << "List " << idx++ << ":\n";
    for (auto &n : x.names) {
      cout << '\t' << n << '\n';
    }
  }
}
