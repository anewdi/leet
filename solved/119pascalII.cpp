#include <iostream>
#include <math.h>
#include <vector>

class Solution {
public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<std::vector<int>> out = {{1}};

    for (int i = 1; i < rowIndex + 1; ++i) {
      std::vector<int> tmp;

      for (int u = 0; u <= i; ++u) {
        tmp.push_back((u == 0 || u == i) ? 1
                                         : out[i - 1][u] + out[i - 1][u - 1]);
      }
      out.push_back(tmp);
    }

    return out.back();
  }
};

int main() {
  Solution aa;
  std::vector<int> res = aa.getRow(3);

  for (int num : res) {
    std::cout << num;
  }
  std::cout << std::endl;
}
