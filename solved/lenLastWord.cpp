#include <iostream>

class Solution {
    public:
        int lengthOfLastWord(std::string s) {
            int count = 0;

            for (int i = s.length()-1; i >= 0; --i){
                char ch = s[i];
                if (ch != ' '){
                    count++;
                } else if (count){
                    break;
                }
            }
            return count;
        }
};

int main() {
    Solution aa;
    std::string s = "a";
    std::cout <<  aa.lengthOfLastWord(s);
}
