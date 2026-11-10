class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        int first = 1;
        int second = 2;
        for(int i = 3; i <= n ;i++){
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

/*1. You can climb either 1 step or 2 steps at a time.
2. To reach step n, you can come from:
Step n-1 (1 step).
Step n-2 (2 steps).
3. Therefore, the formula is:
[dp[n] = dp[n-1] + dp[n-2]]
4.Base cases:
   - n = 1 → 1 way.
   - n = 2 → 2 ways.*/