class Solution {
public:
    string multiply(string num1, string num2) {
        
        int m = num1.length();
        int n = num2.length();
        vector<int> res(m+n,0);
        // accesssing and traversing the digits from last of both the nums.
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