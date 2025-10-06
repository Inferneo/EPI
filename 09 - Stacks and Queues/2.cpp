// Evaluate RPN Expressions

#include <sstream>
#include <stack>
#include <string>

using std::getline;
using std::stack;
using std::stoi;
using std::string;
using std::stringstream;

int Eval(const string &RPN_expression) {
  stack<int> intermediate_results;
  stringstream ss(RPN_expression);
  string token;
  const char kDelimiter = ',';

  while (getline(ss, token, kDelimiter)) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      const int y = intermediate_results.top();
      intermediate_results.pop();
      const int x = intermediate_results.top();
      intermediate_results.pop();
      switch (token.front()) {
      case '+':
        intermediate_results.emplace(x + y);
        break;
      case '-':
        intermediate_results.emplace(x - y);
        break;
      case '*':
        intermediate_results.emplace(x * y);
        break;
      case '/':
        intermediate_results.emplace(x / y);
        break;
      }
    } else { // token is a number.
      intermediate_results.emplace(stoi(token));
    }
  }

  return intermediate_results.top();
}