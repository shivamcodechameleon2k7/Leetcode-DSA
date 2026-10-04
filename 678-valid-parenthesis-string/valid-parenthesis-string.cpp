
class Solution {
public:
    bool checkValidString(string s) {

        stack<int> open;
        stack<int> star;

        for (int i = 0; i < s.length(); i++) {

            // Store index of opening bracket
            if (s[i] == '(') {
                open.push(i);
            }

            // Store index of *
            else if (s[i] == '*') {
                star.push(i);
            }

            // Closing bracket
            else {

                // If we have an opening bracket, use it
                if (!open.empty()) {
                    open.pop();
                }

                // Otherwise use * as an opening bracket
                else if (!star.empty()) {
                    star.pop();
                }

                // No opening bracket or * available
                else {
                    return false;
                }
            }
        }

        // Match remaining '(' with '*'
        while (!open.empty() && !star.empty()) {

            // * must come after (
            if (open.top() < star.top()) {
                open.pop();
                star.pop();
            }
            else {
                return false;
            }
        }

        // If opening brackets are still left,
        // they cannot be matched
        if (!open.empty()) {
            return false;
        }

        return true;
    }
};

