#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int amount = 0;
    int size = flowerbed.size();

    if (size < 2) {
      amount += 1 - flowerbed[0];
      return amount >= n;
    }

    if (!flowerbed[1]) {
      amount += 1 - flowerbed[0];
    }

    int since1 = 0;

    for (int i = 1; i < size; i++) {
      if (flowerbed[i] == 1) {
        since1 = 0;
      } else {
        since1++;
      }

      if (since1 == 3) {
        amount++;
        since1 = 1;
      }
    }

    amount += since1 / 2;

    return amount >= n;
  }
};

int main() {
  Solution s1;
  vector<int> flowerbed = {1, 0, 0, 0, 1};
  cout << s1.canPlaceFlowers(flowerbed, 1);
}
