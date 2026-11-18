class Solution {
public:
    int minChanges(string s) {
        int minm = 0;
        for(int i = 0; i < s.size();i += 2){
            if(s[i] != s[i+1]){
                minm++;
            }
        }
        return minm;
    }
};

/*
Code	        Core reason
int ans = 0;	Start counting changes from zero.
i += 2	        Process independent pairs.
s[i] != s[i+1]	Identify pairs that are not beautiful.
ans++	        One character change fixes that pair.
return ans	    Return the minimum total changes.

*/