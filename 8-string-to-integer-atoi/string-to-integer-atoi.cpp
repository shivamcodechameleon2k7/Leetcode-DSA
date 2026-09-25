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
            if (res > INT_MAX / 10 ||
            (res == INT_MAX / 10 && digit > 7)) {
                if(sign == -1){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }  
            }
            res = res * 10 + digit;
            i++; 
        } 
         return res * sign; 
    }
};