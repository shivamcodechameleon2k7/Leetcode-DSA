
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = nums1[0];
        bool hasOdd = false;
        for (int x : nums1) {
            minVal = min(minVal, x);
            if (x % 2 != 0) {
                hasOdd = true;
            }
        }
        // We can make all odd if the global minimum is odd.
        // We can make all even if there are no odd numbers to begin with.
        return (minVal % 2 != 0) || !hasOdd;
    }
};
