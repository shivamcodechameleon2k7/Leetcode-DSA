class Solution {
public:
    int scoreOfParentheses(string s) {
        // Stack stores the score of each parentheses level
        stack<int> st;
        // Start with score 0 for the outermost level
        st.push(0);
        // Traverse every character of the string
        for(char ch : s) {
            // If we get '(' → enter a new level
            if(ch == '(') {
                st.push(0);
            }
            // If we get ')' → complete the current level
            else {
                // Get the score inside the current parentheses
                int inner = st.top();
                // Remove the current level
                st.pop();
                int score;
                // If nothing was inside → "()"
                // Score = 1
                if(inner == 0) {
                    score = 1;
                }
                // If something was inside → "(A)"
                // Score = 2 × score of A
                else {
                    score = 2 * inner;
                }
                // Add this score to the previous level
                st.top() += score;
            }
        }
        // Final score of the complete string
        return st.top();
    }
};