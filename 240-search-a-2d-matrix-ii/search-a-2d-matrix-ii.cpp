class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Finds the number of rows  and columns in the matrix.matrix[0] means the first row.
        int rows = matrix.size();
        int colm = matrix[0].size();

        // Starts from the first row.
        int row = 0;

        // Starts from the last column.Therefore, we start at the top-right corner.
        int col = colm - 1;
        // Keeps searching while row and col are inside the matrix. row < rows → don't go below the last row. col >= 0 → don't go beyond the left edge.
        while(row < rows && col >= 0){
            // Checks whether the current element is the target. return true; Target is found. Stop searching and return true.
            if (matrix[row][col] == target) {
                return true;
            }

            // Current element is greater than the target.
            // Because we're starting from the top-right, we move left.
            // col--;
            // Moves one column to the left.
            else if (matrix[row][col] > target) {
                col--;
            }


            // This means the current element is smaller than the target.
            // row++;
            // Moves one row down.
            else {
               row++;
            }
        }
        // If the loop finishes without finding the target, it means the target isn't present.
        // So we return false.
        return false;
    }
// whole logic in 3 lines
// Current == target → FOUND → true
// Current > target  → LEFT
// Current < target  → DOWN
};