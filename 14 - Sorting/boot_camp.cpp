#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Student {
  bool operator<(const Student &that) const { return name < that.name; }

  string name;
  double grade_point_average;
};

void SortByGPA(vector<Student> *students) {
  std::sort(students->begin(), students->end(),
            [](const Student &a, const Student &b) {
              if (a.grade_point_average != b.grade_point_average) {
                return a.grade_point_average > b.grade_point_average;
              }
              return a.name < b.name;
            });
}

void SortByName(vector<Student> *students) {
  // Rely on the operator< defined in Student.
  std::sort(students->begin(), students->end());
}