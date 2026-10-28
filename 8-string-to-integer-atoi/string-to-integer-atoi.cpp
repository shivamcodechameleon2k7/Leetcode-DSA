class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.length() && s[i] == ' '){
            i++;
        }
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            sign = 1;
            i++;
        }
        int res = 0;
        while(i < s.length() && s[i]>='0' && s[i] <= '9'){
            int digit = s[i] - '0';

            // This code checks if the number is going to become too large before adding the next digit. Since the biggest positive integer is `2147483647`, `res` should not go beyond `214748364`. If `res` is exactly `214748364`, the next digit can only be `7`; `8` or `9` would make it too large. If the number becomes too large, we return `INT_MAX` for a positive number and `INT_MIN` for a negative number. Otherwise, we continue adding the digit normally.
            if (res > INT_MAX / 10 ||
            (res == INT_MAX / 10 && digit > 7)) {
                if(sign == -1){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }  
            }
            // f there is NO overflow, build the number
            res = res * 10 + digit;
            i++; 
        } 
         return res * sign; 
    }
};