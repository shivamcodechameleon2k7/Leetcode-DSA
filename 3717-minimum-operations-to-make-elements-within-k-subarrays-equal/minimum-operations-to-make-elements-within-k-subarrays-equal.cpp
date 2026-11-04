
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Two halves of the sliding window
        multiset<int> low, high;

        long long sumLow = 0;
        long long sumHigh = 0;

        // Balance both halves
        auto balance = [&]() {

            while (low.size() > high.size() + 1) {

                int val = *low.rbegin();

                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size()) {

                int val = *high.begin();

                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        // Insert an element
        auto add = [&](int val) {

            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            }
            else {
                high.insert(val);
                sumHigh += val;
            }

            balance();
        };

        // Remove one occurrence of an element
        auto remove = [&](int val) {

            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            }
            else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            balance();
        };

        // Step 1: Calculate costs of all windows
        vector<long long> costs;

        for (int i = 0; i < n; i++) {

            // Add incoming element
            add(nums[i]);

            // Remove outgoing element
            if (i >= x) {
                remove(nums[i - x]);
            }

            // Calculate cost when window size becomes x
            if (i >= x - 1) {

                int median = *low.rbegin();

                long long leftCost =
                    1LL * median * low.size() - sumLow;

                long long rightCost =
                    sumHigh - 1LL * median * high.size();

                costs.push_back(leftCost + rightCost);
            }
        }

        // Step 2: DP initialization
        long long INF = LLONG_MAX / 2;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        // Step 3: DP transitions
        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= k; j++) {

                // Option 1: Skip current element
                dp[i][j] = dp[i - 1][j];

                // Option 2: Select a window of size x
                if (i >= x && j >= 1 &&
                    dp[i - x][j - 1] != INF) {

                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + costs[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
