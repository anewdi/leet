#include <cstring>
#include <iostream>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    int slen = needle.length();
    for (int i = 0, u = haystack.length(); i < u - slen + 1; ++i) {
      std::string sub;
      sub.resize(slen);
      std::memcpy(&sub[0], &haystack[i], slen);
      if (sub == needle) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution aa;
  std::cout << aa.strStr("sadbutsad", "sad");
}
