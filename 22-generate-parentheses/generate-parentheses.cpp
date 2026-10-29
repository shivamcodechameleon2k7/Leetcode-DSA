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



/*backtrack(int n, string curr, int open, int close, vector<string>& ans) — Ye helper function hai jo valid parentheses combinations generate karta hai. n pairs ki limit hai, curr current string hai, aur open aur close counters hain.
if(open == n && close == n) — Jab opening aur closing brackets dono ki count n ho jaati hai, combination complete ho jaata hai.
ans.push_back(curr); — Complete combination ko ans vector mein store karta hai. return us recursive call ko stop kar deta hai.
if(open < n) — Check karta hai ki kya aur opening bracket ( add kar sakte hain. Maximum n opening brackets allowed hain.
curr.push_back('('); — Current string ke end mein opening bracket add karta hai. Example: "(" se "((" ban sakta hai.
open++; — Opening bracket counter ko 1 se increase karta hai. Agar open = 1 tha, toh ab open = 2 hoga.
backtrack(n, curr, open, close, ans); — Updated values ke saath recursive call karta hai. Call complete hone ke baad open-- counter ko purani value par restore karta hai, aur curr.pop_back() added bracket ko remove karta hai.
if(close < open) — Closing bracket ) tabhi add hota hai jab opening brackets ki count closing brackets se zyada ho. Isse invalid combinations, jaise ")(", nahi bante.
close++; ... close--; curr.pop_back(); — Closing bracket add karne ke baad close increase hota hai. Recursive exploration ke baad close-- counter restore karta hai aur curr.pop_back() last bracket remove karta hai. Ye bhi backtracking hai.
generateParenthesis(int n) — ans aur empty curr initialize karta hai, phir backtrack(n, curr, 0, 0, ans) se recursion start karta hai aur end mein ans return karta hai.*/