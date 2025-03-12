#include <iostream>

class Solution {
public:
  bool isPalindrome(std::string s) {
    std::string news;
    for (int i = 0, u = s.length(); i < u; ++i) {
      if (std::isalnum(s[i])) {
        news += std::tolower(s[i]);
      }
    };

    for (int i = 0, u = news.length(); i < u / 2; ++i) {
      if (news[i] != news[u - i - 1]) {
        return false;
      };
    }

    return true;
  }
};

int main() {
  Solution aa;

  // std::cout << aa.isPalindrome("A man, a plan, a canal: Panama") <<
  // std::endl;
  std::cout << aa.isPalindrome("oP") << std::endl;
}
