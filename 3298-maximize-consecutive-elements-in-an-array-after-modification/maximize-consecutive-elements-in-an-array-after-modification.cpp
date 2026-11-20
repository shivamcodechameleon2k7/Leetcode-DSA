
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for(int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;

            ans = max(ans, max(dp[x], dp[x + 1]));
        }

        return ans;
    }
};


/*
sort(nums.begin(), nums.end()) – Sort the array so we process elements in increasing order.

2. unordered_map<int, int> dp – Stores the maximum length of a consecutive sequence ending at a particular value.

3. int ans = 0 – Stores the maximum consecutive sequence length found so far.

4. for(int x : nums) – Traverse each element of the sorted array.

5. dp[x + 1] = dp[x] + 1 – Increase the current element by 1 and extend the sequence ending at x.

6. dp[x] = dp[x - 1] + 1 – Keep the current element unchanged and extend the sequence ending at x - 1.

7. ans = max(ans, max(dp[x], dp[x + 1])) – Update the answer with the longest sequence obtained from either choice.

8. return ans – Return the maximum length.
Core logic to remember 💡
For every element, we have two choices:
- Keep x as it is.
- Change x into x + 1.
We use DP to remember the longest consecutive sequence ending at each possible value.

Time Complexity: \(O(n\log n)\)

Space Complexity: \(O(n)\)
*/