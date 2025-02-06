#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {

    vector<bool> result = {};
    int max = 0;

    for (int candy : candies) {
      if (candy > max) {
        max = candy;
      };
    }

    for (int candy : candies) {
      if (candy + extraCandies >= max) {
        result.push_back(true);
      } else {
        result.push_back(false);
      }
    }

    return result;
  }
};

int main() {
  Solution somesolution;

  vector<int> candies = {2, 3, 5, 1, 3};

  vector<bool> bools = somesolution.kidsWithCandies(candies, 3);
}
