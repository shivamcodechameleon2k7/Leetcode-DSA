class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length();i++){
            if(s[i] == 40 || s[i] == 91 || s[i] == 123){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if((st.top() == 40 && s[i] == 41) ||
                (st.top() == 91 && s[i] == 93) ||
                (st.top() == 123 && s[i] == 125)){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();  
    }
};