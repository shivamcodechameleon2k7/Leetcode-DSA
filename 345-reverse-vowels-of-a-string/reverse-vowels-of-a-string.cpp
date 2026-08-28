class Solution {
public:
    bool isVowel(char c){
        return string("aeiouAEIOU").find(c) != string::npos;
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            while(left < right && !isVowel(s[left])){
                left++;
            }
            while(left < right && !isVowel(s[right])){
                right--;
            }
            if(left < right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s; 
    }   
};