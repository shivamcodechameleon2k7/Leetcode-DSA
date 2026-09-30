class Solution {
public:
    string addStrings(string num1, string num2) {

        //addition happens from right to left
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        string res;
        while(i >= 0 || j >= 0){
            int digit1;
            int digit2;
            if(i >= 0){
                //character-to-integer conversion
                digit1 = num1[i] - '0';
            }
            else{
                digit1 = 0;
            }
            if(j >= 0){
                //character-to-integer conversion
                digit2 = num2[j] - '0';
            }
            else{
                digit2 = 0;
            }
            int sum = digit1 + digit2 + carry;

            //They separate the sum into two parts: the digit you put in the current position and the carry you take to the next position.
            carry = sum / 10;
            int digit = sum % 10;

            //integer-to-character conversion
            res += digit + '0';

            //addition happens from right to left
            i--;
            j--;  
        }
        if(carry > 0){
            res += carry + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};