class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose of the matrix 
        for(int i = 0; i < matrix.size();i++){
            for( int j = i+1;j<matrix.size();j++){
                    swap(matrix[i][j],matrix[j][i]);
                } 
            // reverse the elements in the matrix after transpose to there corresponding position.
            int left = 0;
            int right = matrix.size()-1;
            while(left<right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }   
    }
};