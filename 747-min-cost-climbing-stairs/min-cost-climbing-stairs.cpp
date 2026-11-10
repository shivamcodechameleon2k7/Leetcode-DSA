class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev2 = 0;
        int prev1 = 0;

        for (int i = 2; i <= n; i++) {
            int curr = min(prev1 + cost[i - 1],prev2 + cost[i - 2]);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};



/*
1. We can start from step 0 or step 1.
2. We can climb either 1 or 2 steps at a time.
3. To reach step i, we have two choices:
   - From step i-1: pay cost[i-1].
   - From step i-2: pay cost[i-2].
4. Choose the minimum cost between these two choices.
5. prev1 stores the minimum cost to reach the previous step.
6. prev2 stores the minimum cost to reach the step before that.
7. Finally, return prev1 because reaching step n means reaching the top.*/