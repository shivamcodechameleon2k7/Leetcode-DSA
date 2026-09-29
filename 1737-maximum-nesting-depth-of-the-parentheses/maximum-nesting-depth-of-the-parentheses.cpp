class Solution {
public:

// takes a string s
// returns an int
// the returned integer is the maximum nesting depth
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;
        for(char ch : s){


            // open parenthesis present -> one more level inside.
            if(ch == '('){
                depth++;

                // we check whether the current depth is the largest depth so far.
                ans = max(ans,depth);
            }

            // closed parenthesis present-> leaving the current level of closing.
            else if(ch == ')'){ 
                depth--;
            }
        }
        return ans;
    }
};