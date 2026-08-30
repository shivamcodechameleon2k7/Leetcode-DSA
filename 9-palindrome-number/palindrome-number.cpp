class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if (x != 0 && x % 10 == 0){
            return false;
        }
        int reverse = 0;
        while(x > reverse){
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
            
        }
        if(x == reverse || x == reverse /10){
            return true;
        }
        else{
            return false;
        }
        
    }
};