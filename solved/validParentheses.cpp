#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    // Implementation 1
    stack<char> closer;

    for (char bracket : s) {
      switch (bracket) {
      case '{':
        closer.push('}');
        break;
      case '(':
        closer.push(')');
        break;
      case '[':
        closer.push(']');
        break;
      default:
        if (closer.empty() || closer.top() != bracket) {
          return false;
        }
        closer.pop();
      };
    }

    // Implementation 2
    unordered_map<char, char> valids = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

    for (char bracket : s) {
      if (valids.find(bracket) != valids.end()) {
        closer.push(valids[bracket]);
      } else if (closer.empty() || closer.top() != bracket) {
        return false;
      } else {
        closer.pop();
      }
    }

    return closer.empty();
  };
};

int main() {
  Solution aa;
  cout << aa.isValid(")");
}
