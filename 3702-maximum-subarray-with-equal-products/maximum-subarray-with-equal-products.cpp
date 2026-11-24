
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long product = 1;
            long long gcdVal = 0;
            long long lcmVal = 1;

            for(int j = i; j < n; j++) {

                gcdVal = gcd(gcdVal, (long long)nums[j]);

                long long g = gcd(lcmVal, (long long)nums[j]);

                lcmVal = (lcmVal / g) * nums[j];

                if(product > LLONG_MAX / nums[j]) {
                    break;
                }

                product *= nums[j];

                if(product == gcdVal * lcmVal) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

/*subarray is valid when:

Product = GCD \times LCM


We need to return the maximum length of such a subarray.
2. Approach – Brute Force
1. Use i to select the starting index.
2. Use j to extend the subarray.
3. Maintain three variables:
   - product = multiplication of elements.
   - gcdVal = GCD of elements.
   - lcmVal = LCM of elements.
4. Check whether:

product = gcdVal \times lcmVal


5. If true, update:

ans = max(ans, j - i + 1)

6. Return ans.*/