#include <iostream>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string result = a.length() < b.length() ? b : a;
    std::string &small = a.length() < b.length() ? a : b;

    int min = small.length();
    int max = result.length();
    int carry = 0;

    // add parts
    for (int i = 1; i <= min; ++i) {
      carry += small[min - i] + result[max - i] - 2 * '0';
      result[max - i] = carry % 2 + '0';
      carry /= 2;
    }

    // Figure out carry if still remaining
    if (carry) {
      for (int i = max - min - 1; i >= 0; --i) {
        char r = result[i];

        if (r == '0') {
          result[i] = '1';
          return result;
        }
        result[i] = '0';
      }
      result.insert(result.begin(), '1');
    }

    return result;
  };
};

int main() {
  Solution aa;

  std::string s1 = "11";
  std::string s2 = "1";

  std::cout << aa.addBinary(s1, s2) << std::endl;
}
