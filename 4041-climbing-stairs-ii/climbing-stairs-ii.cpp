class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + costs[i - 1] + j * j);
                }
            }
        }

        return dp[n];
    }
};


/*dp[i] stores the minimum cost required to reach stair i.
dp[0] = 0 because starting at stair 0 costs nothing.
You can climb either 1, 2, or 3 stairs at a time.
j represents the number of stairs climbed in one jump.
costs[i-1] represents the cost of reaching stair i.
j * j represents the additional cost of the jump.
Take the minimum cost among all three possible jumps.
Finally, return dp[n].*/