#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";

    string res = "";

    sort(strs.begin(), strs.end());
    int n = strs.size();
    string first = strs[0], last = strs[n - 1];
    for (int i = 0; i < min(first.size(), last.size()); i++) {
      if (first[i] != last[i]) {
        return res;
      }
      res += first[i];
    }

    return res;
  }
};

int main() {
  Solution a1;
  vector<string> strings = {"flower", "flow", "flight"};
  cout << a1.longestCommonPrefix(strings);
}
