
// class Solution {
// public:
//     int minimumSumSubarray(vector<int>& nums, int l, int r) {
//         int ans = INT_MAX;

//         for(int i = 0; i < nums.size(); i++) {
//             for(int j = i; j < nums.size(); j++) {
//                 int sum = 0;
//                 int len = j - i + 1;

//                 if(len >= l && len <= r) {
//                     for(int k = i; k <= j; k++) {
//                         sum += nums[k];
//                     }

//                     if(sum > 0) {
//                         ans = min(ans, sum);
//                     }
//                 }
//             }
//         }
//         if(ans == INT_MAX) {
//             return -1;
//         }

//         return ans;
//     }
// };


/*
Initialize ans = INT_MAX.
Generate subarrays using two loops.
Initialize sum = 0 for each subarray.
Calculate len = j - i + 1.
Check whether len is between l and r.
Use the third loop to calculate the actual sum.
If sum > 0, update ans.
After all loops, return -1 if ans == INT_MAX; otherwise return ans*/



class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            long long sum = 0;

            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];

                int len = j - i + 1;

                if(len >= l && len <= r) {
                    if(sum > 0) {
                        ans = min(ans, (int)sum);
                    }
                }

                if(len > r) {
                    break;
                }
            }
        }

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};
