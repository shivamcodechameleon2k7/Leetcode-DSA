#include<climits>
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int digit = x % 10;
            x = x / 10;
            int MAX = 2147483647;
            int MIN = -2147483648;
            if(rev > MAX / 10){
                return 0;
            }
            if(rev < MIN / 10){
                return 0;
            }
            rev = rev * 10 + digit;
        }
    return rev;   
    }
};