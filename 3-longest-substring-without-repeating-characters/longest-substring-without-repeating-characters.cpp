class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        set<char>seen;
        int max_length = 0;
        while(right<s.size()){
            if(seen.find(s[right]) == seen.end()){
                seen.insert(s[right]);
                right++;
                int curr_length = right - left;
                max_length = max(max_length,curr_length);
            }
            else if(seen.find(s[left]) != seen.end()){
                seen.erase(s[left]);
                left++;
            }
        }
    return max_length;
    }      
};