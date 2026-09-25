class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int colm = matrix[0].size();
        int low = 0;
        int high = rows * colm - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int row = mid / colm;
            int col = mid % colm;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        } 
        return false;    
    }
};