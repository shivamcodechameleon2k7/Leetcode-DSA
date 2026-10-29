class Solution {
public:
    void backtrack(int n, string curr, int open, int close,
                    vector<string>& ans){
        
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            curr.push_back('(');
            open++;
            backtrack(n, curr, open, close, ans);
            open--;
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            close++;
            backtrack(n,curr,open,close,ans);
               close--;
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        backtrack(n, curr, 0, 0, ans);
        return ans;
    }
};



// class Solution {
// public:
//     void backtrack(int n, string curr, int open, int close,
//                    vector<string>& ans) {

//         if (open == n && close == n) {
//             ans.push_back(curr);
//             return;
//         }

//         if (open < n) {
//             curr.push_back('(');
//             backtrack(n, curr, open + 1, close, ans);
//             curr.pop_back();
//         }

//         if (close < open) {
//             curr.push_back(')');
//             backtrack(n, curr, open, close + 1, ans);
//             curr.pop_back();
//         }
//     }

//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         string curr = "";

//         backtrack(n, curr, 0, 0, ans);

//         return ans;
//     }
// };
