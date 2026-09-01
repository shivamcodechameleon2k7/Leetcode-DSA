class Solution {
public:
    string longestPalindrome(string s) {
        
        string longest = s.substr(0, 1);
        for(int center = 0 ; center < s.size();center++){
            int i = center-1;
            int j = center+1;
            while(i>=0 && j < s.size()){
                if(s[i]==s[j]){
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
            int start = i+1;
            int length = j-i-1;
            if(length > longest.size()){
                longest = s.substr(start,length);
            }

            i = center;
            j = center+1;
            while(i>=0 && j < s.size()){
                if(s[i] == s[j]){
                    i--;
                    j++;
                }
                else{
                    break;
                    }
                }
                start = i+1;
                length =j-i-1;
                if(length > longest.size()){
                    longest = s.substr(start,length);
                }
            }return longest;      
    }
};