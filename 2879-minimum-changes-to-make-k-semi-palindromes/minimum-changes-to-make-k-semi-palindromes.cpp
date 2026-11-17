
class Solution {
public:
    int minimumChanges(string s, int k) {

        int n = s.size();

        // 1. Initialize cost array
        vector<vector<int>> cost(n, vector<int>(n, 1e9));


        // 2. Calculate cost of every substring
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                // Find proper divisors
                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;

                    // Compare characters
                    for (int r = 0; r < d; r++) {

                        int left = i + r;
                        int right = i + len - d + r;

                        while (left < right) {

                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }


        // 3. Initialize DP array
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 1e9));

        dp[0][0] = 0;


        // 4. Apply DP
        for (int p = 1; p <= k; p++) {

            for (int i = 1; i <= n; i++) {

                for (int j = 0; j < i; j++) {

                    if (i - j < 2) continue;

                    if (dp[p - 1][j] == 1e9) continue;

                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }


        // 5. Return answer
        return dp[k][n];
    }
};
