
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;

        // Find the minimum element
        for(int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
        }

        int moves = 0;

        // Calculate total moves
        for(int i = 0; i < nums.size(); i++) {
            moves += nums[i] - mini;
        }

        return moves;
    }
};


/*Function declaration: int minMoves(vector<int>& nums) takes an integer array and returns the minimum moves required to make all elements equal.

2. Initialize minimum: int mini = INT_MAX; initializes the minimum variable with the largest possible integer so we can find the smallest array element.
3. First loop: for(int i = 0; i < nums.size(); i++) traverses the entire array to check every element.
4. Find minimum: mini = min(mini, nums[i]); compares the current element with the stored minimum and updates mini whenever a smaller element is found.
5. Initialize moves: int moves = 0; creates a variable to store the total number of moves required.
6. Second loop: for(int i = 0; i < nums.size(); i++) traverses the array again to calculate the moves required for each element.
7. Calculate difference: moves += nums[i] - mini; subtracts the minimum element from the current element and adds the difference to the total moves.
8. Understand the calculation: For [1, 2, 3], the differences are (1-1) + (2-1) + (3-1) = 0+1+2 = 3. Therefore, the total moves are 3.
9. Return result: return moves; returns the total number of moves calculated by the program.
10. Core logic: Instead of incrementing n-1 elements by 1 in every operation, we can think of decrementing one element by 1. Therefore, making every element equal to the minimum element gives the minimum number of moves.
Complexity: Time = \(O(n)\), Space = \(O(1)\).*/