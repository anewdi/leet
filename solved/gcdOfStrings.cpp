#include <iostream>
using namespace std;

class Solution {
public:
  string concatString(string solo, int times) {
    string final;
    for (int i = 0; i < times; i++) {
      final += solo;
    }

    return final;
  }
  int denominator(int integer1, int integer2) {

    int min, max;

    if (integer1 > integer2) {
      min = integer2;
      max = integer1;
    } else {
      min = integer1;
      max = integer2;
    }

    if (max % min == 0) {
      return min;
    }

    int factor;

    for (int i = 2; i <= min / 2; i++) {
      factor = min / i;
      if (integer1 % factor == 0 && integer2 % factor == 0) {
        return factor;
      }
    }

    return 1;
  }

  string gcdOfStrings(string str1, string str2) {
    int l1 = str1.length();
    int l2 = str2.length();
    int denom = denominator(l1, l2);

    string common;

    int max = l1 > l2 ? l2 : l1;

    for (int i = 0; i < max; i++) {
      if (str1[i] == str2[i]) {
        common += str1[i];

        int clength = common.length();

        if (concatString(common, l1 / clength) == str1 &&
            concatString(common, l2 / clength) == str2) {
          return concatString(common, denom / clength);
        };
      } else {
        break;
      }
    }
    return "";
  }
};

int main() {
  Solution somesolution;
  cout << somesolution.gcdOfStrings("AAA", "AA");
}
