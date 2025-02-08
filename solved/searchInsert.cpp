#include <iostream>
#include <vector>

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    int beg = 0;
    int end = nums.size() - 1;

    while (beg <= end) {
      int mid = beg + (end - beg) / 2;
      int midnum = nums[mid];

      if (target == midnum) {
        return mid;
      } else if (target < midnum) {
        end = mid - 1;
      } else if (target > midnum) {
        beg = mid + 1;
      }
    }

    return beg;
  }
};

int main() {
  Solution aa;
  std::vector<int> nums = {1, 2, 3, 5};
  std::cout << aa.searchInsert(nums, 4) << std::endl;
}
