#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
      if (mp.find(target - nums[i]) == mp.end()) {
        mp[nums[i]] = i;
      } else {
        return {mp[target - nums[i]], i};
      }
    }

    return {-1, -1};
  }
};

int main() {
  Solution s1;
  vector<int> nums = {5, 5, 11, 15};
  vector<int> res = s1.twoSum(nums, 10);
  for (int num : res) {
    cout << num;
  }
}
