#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    if (numRows < 1) {
      return {{}};
    }

    std::vector<std::vector<int>> out = {{1}};

    for (int i = 1; i < numRows; ++i) {
      std::vector<int> tmp;

      for (int u = 0; u <= i; ++u) {
        tmp.push_back((u == 0 || u == i) ? 1
                                         : out[i - 1][u] + out[i - 1][u - 1]);
      }
      out.push_back(tmp);
    }

    return out;
  }
};

int main() {
  Solution aaa;
  std::vector<std::vector<int>> trig = aaa.generate(5);
  for (std::vector<int> row : trig) {
    for (int num : row) {
      std::cout << num;
    }
    std::cout << std::endl;
  }
}
