#include <iostream>
#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int end = n + m - 1;

    while (p2 >= 0) {
      if (p1 >= 0 && nums1[p1] > nums2[p2]) {
        nums1[end] = nums1[p1];
        p1--;
      } else {
        nums1[end] = nums2[p2];
        p2--;
      }
      end--;
    }
  }
};

int main() {
  Solution aa;
  std::vector n1 = {1, 2, 3, 0, 0, 0};
  std::vector n2 = {2, 5, 6};
  aa.merge(n1, 3, n2, 3);
  for (int i : n1) {
    std::cout << i;
  }
}
