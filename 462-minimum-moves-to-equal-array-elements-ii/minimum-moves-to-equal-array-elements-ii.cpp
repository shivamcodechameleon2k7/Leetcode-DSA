class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Find the median
        int n = nums.size();
        int median = nums[n / 2];

        // Step 3: Calculate total moves
        int moves = 0;

        for(int i = 0; i < n; i++) {
            moves += abs(nums[i] - median);
        }

        return moves;
    }
};


/*Sort the array: First, arrange all elements in ascending order using sort(nums.begin(), nums.end()).
Find the median: The median is the middle element of the sorted array. We use nums[n/2] to get it.
Why median? The median gives the minimum total moves when making all array elements equal.
Calculate moves: Traverse the array and calculate the absolute difference between every element and the median using abs(nums[i] - median).
Return the answer: Add all these differences and return the total.*/