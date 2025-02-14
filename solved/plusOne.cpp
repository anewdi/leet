#include <vector>
#include <iostream>

class Solution {
    public: 
        std::vector<int> plusOne(std::vector<int>& digits){
            int i = digits.size()-1;

            while(i >= 0){
                if (digits[i] == 9){
                    digits[i] = 0;
                } else{
                    digits[i]++;
                    break;
                }
                --i;
            }

            if (i == -1) digits.insert(digits.begin(),1);

            return digits;
        }
};

int main(){
    Solution aa;
    std::vector<int> arr = {9};
    for (int num: aa.plusOne(arr)){
        std::cout << num << std::endl;
    }
}
