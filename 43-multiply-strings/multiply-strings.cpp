class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        vector<int> res(m+n,0);
        for(int i = m-1; i>= 0; i--){
            for(int j = n-1; j>= 0;j--){
                int digit1 = num1[i]-'0';
                int digit2 = num2[j]-'0';
                int prod = digit1 * digit2;
                int sum = res[i+j+1] + prod;
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }
        string ans = "";
        int start = 0;
        while(start < res.size() && res[start] == 0) {
            start++;
        } 
        if(start == res.size()) {
            return "0";
        }
        for(int i = start; i < res.size(); i++) {
            ans += res[i] + '0';
        }
        return ans;
    }
};









// Find lengths

// int m = num1.length();
// int n = num2.length();

// → m and n store the number of digits.

// Create result array

// vector<int> res(m + n, 0);

// → An m-digit × n-digit multiplication can have at most m+n digits, so we create m+n positions, initially 0.

// Traverse from right to left

// for(int i = m - 1; i >= 0; i--)

// and

// for(int j = n - 1; j >= 0; j--)

// → Just like normal multiplication, start from the rightmost digits.

// Convert characters to digits

// int digit1 = num1[i] - '0';
// int digit2 = num2[j] - '0';

// → '7' - '0' = 7.

// Multiply the two digits

// int prod = digit1 * digit2;

// → Example: 6 × 3 = 18.

// Add to the existing result position

// int sum = res[i + j + 1] + prod;

// → Multiple digit multiplications can contribute to the same position.

// Store the current digit

// res[i + j + 1] = sum % 10;

// → % 10 extracts the last digit.
// Example: 18 % 10 = 8.

// Store the carry

// res[i + j] += sum / 10;

// → / 10 extracts the carry.
// Example: 18 / 10 = 1.

// After multiplication, convert the array to string

// string ans = "";

// Skip leading zeros

// while(start < res.size() && res[start] == 0)

// → Prevents results like "000560".

// Handle multiplication resulting in zero

// if(start == res.size())
//     return "0";

// Convert each digit into a character

// ans += res[i] + '0';

// → Example:
// 5 + '0' → '5'.

// Return the final string

// return ans;
//  Main idea to remember

// String digits → multiply → add existing value → separate digit & carry → store in result array → convert array to string.

// Time: O(m × n)
// Space: O(m + n)