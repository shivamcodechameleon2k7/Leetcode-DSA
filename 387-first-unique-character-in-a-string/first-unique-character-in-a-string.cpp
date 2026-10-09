class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        queue<int> Q;
        for(int i = 0;i < s.length();i++){
            if(m.find(s[i]) == m.end()){
                Q.push(i);
            }
            m[s[i]]++;
            while(Q.size() > 0 && m[s[Q.front()]] > 1){
                Q.pop();
            }
        }
        if(Q.empty()){
            return -1;
        }
        else{
            return Q.front();
        }
    }
};