#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int prev = nums[0];
    int k = 1;

    for (int i = 1, u = nums.size(); i < u; ++i) {
      int num = nums[i];
      if (num != prev) {
        nums[k] = num;
        prev = num;
        k++;
      }
    }

    return k;
  }
};

int main() {
  Solution a1;
  std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  a1.removeDuplicates(nums);
  for (int num : nums) {
    std::cout << num << "\n";
  }
}
