#include <iostream>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    int k = 0;

    for (int i = 0, u = nums.size(); i < u; i++) {
      int num = nums[i];
      if (num != val) {
        nums[k] = num;
        ++k;
      }
    }
    return k;
  }
};

int main() {
  Solution aa;
  std::vector<int> ss = {3, 2, 2, 3};
  std::cout << aa.removeElement(ss, 2);
  for (int num : ss) {
    std::cout << num;
  }
}
