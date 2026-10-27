class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> last(26, 0);
        vector<bool> visited(26, false);
        for(int i = 0; i < s.size();i++){
            last[s[i]-'a'] = i;
        }
        for(int i = 0;i < s.size();i++){
            if(visited[s[i] - 'a']){
                continue;
            }
            while(!st.empty() && st.top() > s[i] && last[st.top() - 'a'] > i){
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};