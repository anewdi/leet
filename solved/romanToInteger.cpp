#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                   {'L', 50},  {'C', 100}, {'D', 500},
                                   {'M', 1000}};

    int sum = 0;
    int prev = 0;
    for (char c : s) {
      int num = mp[c];

      if (num > prev) {
        sum -= 2 * prev;
      }

      sum += num;
      prev = num;
    }

    return sum;
  }
};

int main() {
  Solution ai;
  cout << ai.romanToInt("IVIII");
}
