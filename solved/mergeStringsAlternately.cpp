#include <iostream>
using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string finalword, largest;
    int max;

    if (word2.length() > word1.length()) {
      max = word1.length();
      largest = word2;
    } else {
      max = word2.length();
      largest = word1;
    }

    for (int i = 0; i < max; i++) {
      finalword += word1[i];
      finalword += word2[i];
    }

    finalword += largest.substr(max);

    return finalword;
  }
};
