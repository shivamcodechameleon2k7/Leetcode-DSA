class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()){
            return s;
        }
        bool goingdown = true;
        int row = 0;
        vector<string> rows(numRows);
        for(int i = 0; i < s.size();i++){
            rows[row].push_back(s[i]);
            if(row == 0){
                goingdown = true;
            }
            if(row == numRows-1){
                goingdown = false;
            }
            if(goingdown){
                row++;
            }
            else{
                row--;
            }
        }
        string ans = "";
        for(int i = 0; i < numRows;i++){
                ans += rows[i]; 
            }  
            return ans;   
    } 
};