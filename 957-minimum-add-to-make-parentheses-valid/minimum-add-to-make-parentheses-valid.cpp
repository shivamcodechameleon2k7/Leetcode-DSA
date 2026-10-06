class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() =='('){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        return st.size();

    }
};


// '(' comes → put it in stack
// We need to remember this opening bracket.
// ')' comes → check the stack
// If stack has '(' → remove it because () is a valid pair.
// If stack is empty → put ')' in stack because it has no '(' to match with it.
// After checking the whole string
// Whatever is left in the stack is unmatched brackets.
// Each unmatched bracket needs one new bracket to make the string valid.

// So:

// return st.size();

// means "return the number of unmatched brackets."