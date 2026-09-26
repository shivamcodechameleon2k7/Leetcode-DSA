class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows and columns.

        int rows = matrix.size();
        int colm = matrix[0].size();
        int row = 0;
        int col = colm - 1;

       
        while(row < rows && col >= 0){

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {
                col--;
            }
            else {
               row++;
            }
        }
        return false;
    }
};