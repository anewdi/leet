#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int buy = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); ++i) {
      if (buy > prices[i]) {
        buy = prices[i];
      } else if (prices[i] - buy > profit) {
        profit = prices[i] - buy;
      }
    }
    return profit;
  }
};

int main() {
  Solution aa;

  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  std::cout << aa.maxProfit(prices) << std::endl;
}
