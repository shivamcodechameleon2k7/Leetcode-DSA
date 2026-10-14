class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int left = a.size()-1;
        int right = b.size()-1;
        while(left >= 0 || right >= 0 || carry != 0){
            int sum = carry;
            if(left >= 0){
                sum += a[left]-'0';
            }
            if(right >= 0){
                sum += b[right]-'0';
            }
            left--;
            right--;
            result.push_back((sum%2)+'0');
            carry = sum / 2; 
        }
        reverse(result.begin(),result.end());
        return result;
    }
};




/*final logic is working correctly:
while condition handles remaining digits and carry.
sum = carry includes the previous carry.
Both if statements safely handle strings of different lengths.
left-- and right-- move to the next digits.
(sum % 2) + '0' appends the current binary digit.
sum / 2 calculates the next carry.
reverse() restores the correct order.
Complexity analysis
Let (n) be the length of a and (m) the length of b.
- Time complexity: (O(max(n,m)))
- Space complexity: (O(max(n,m))) for the result string.*/