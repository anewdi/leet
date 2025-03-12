#include <iostream>
#include <vector>

class Solution {
public:
  int singleNumber(std::vector<int> &nums) {
    int result = nums[0];
    for (int i = 1, u = nums.size(); i < u; ++i) {
      result ^= nums[i];
    }

    return result;
  }
};

int main() {
  Solution aa;

  std::vector<int> nums = {2, 2, 1};

  std::cout << aa.singleNumber(nums) << std::endl;
}
