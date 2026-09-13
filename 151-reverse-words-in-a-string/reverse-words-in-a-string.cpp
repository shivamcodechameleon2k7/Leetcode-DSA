class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int right = s.size() - 1;
        // Skip spaces from the end
        while(right>=0){
            while(right >= 0 && s[right] == ' ') {
                right--;
            }
            if(right < 0){
                break;
            }
            // Find the beginning of the last word
            int left = right;
            while(left >= 0 && s[left] != ' ') {
                left--;
            }
            // Add space before every word except the first
            if(!ans.empty()){
                ans.push_back(' ');

            }
            // Last word is from left + 1 to right
            for(int i = left + 1; i <= right; i++) {
                ans.push_back(s[i]);
            }
            
            right = left-1;  
        }
        return ans;
    }
};