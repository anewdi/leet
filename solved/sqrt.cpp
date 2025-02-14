#include <iostream>
#include <math.h>

class Solution {
public:
  int mySqrt(int x) {
    // So here i found the bounds using power of 10**k cirka equal to x and
    // upper bound 10**k+1, but ended up being barley any faster. (5/6log(n) ish
    // instead of log(n) so log(n))
    // int xcpy = x;
    // int ponent = 0;
    // while (xcpy >= 10) {
    //  xcpy /= 10;
    //  ponent++;
    //}

    // int upper = ponent ? std::pow(6.4, ponent) : x;
    // int lower = ponent ? std::pow(3.1, ponent) : 1;
    int upper = x;
    int lower = 1;

    while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      int cand = x / mid;
      if (mid == cand)
        return mid;
      else if (mid < cand)
        lower = mid + 1;
      else
        upper = mid - 1;
    }

    return upper;
  }
};

int main() {
  Solution aa;
  std::cout << aa.mySqrt(4) << std::endl;
}
