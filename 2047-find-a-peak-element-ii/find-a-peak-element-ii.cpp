class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            // Find middle column
            int mid = low + (high - low) / 2;

            // Find maximum element in middle column
            int maxRow = 0;

            for (int i = 1; i < m; i++) {

                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Current element
            int current = mat[maxRow][mid];

            // Find left neighbor
            int left;

            if (mid > 0) {
                left = mat[maxRow][mid - 1];
            }
            else {
                left = -1;
            }

            // Find right neighbor
            int right;

            if (mid < n - 1) {
                right = mat[maxRow][mid + 1];
            }
            else {
                right = -1;
            }

            // Check if current element is a peak
            if (current > left && current > right) {
                return {maxRow, mid};
            }

            // Left neighbor is greater
            else if (left > current) {
                high = mid - 1;
            }

            // Right neighbor is greater
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};