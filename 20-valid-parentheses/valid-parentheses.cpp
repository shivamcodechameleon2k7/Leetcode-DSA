class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length();i++){

            // if the char is an opening character then simply push it in to the stack.
            // if(s[i] == 40 || s[i] == 91 || s[i] == 123){
            //     st.push(s[i]);
            // }

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                // number of closing bracket > opening bracket
                if(st.empty()){
                    return false;
                }

                // this part check if the parenthesis requirement matches or not
                // if same opening and closing bracket is present then pop it or else return false.
                // if((st.top() == 40 && s[i] == 41) ||
                // (st.top() == 91 && s[i] == 93) ||
                // (st.top() == 123 && s[i] == 125)){
                //     st.pop();
                // }


                if((st.top() == '(' && s[i] == ')') ||
                (st.top() == '{' && s[i] == '}') ||
                (st.top() == '[' && s[i] == ']')){
                    st.pop();
                }



                else{
                    return false;
                }
            }
        }
        // number of opening bracket > closing bracket.
        return st.empty();  
    }
};