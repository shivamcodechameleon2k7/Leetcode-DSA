class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int both = min(need1,need2);
        int rem1 = need1 - both;
        int rem2 = need2 - both;
       

        // Option 1: Mixed purchases
        long long option1 = 1LL * both * costBoth
                          + 1LL * rem1 * cost1
                          + 1LL * rem2 * cost2;

        // Option 2: Buy separately
        long long option2 = 1LL * need1 * cost1
                          + 1LL * need2 * cost2;

        // Option 3: Buy only combined packages
        long long option3 = 1LL * max(need1, need2) * costBoth;

        return min({option1, option2, option3});
    }
};


/*min(need1, need2) → Common quantity.
max(need1, need2) → Maximum quantity required.
1LL → Prevents integer overflow during multiplication.*/