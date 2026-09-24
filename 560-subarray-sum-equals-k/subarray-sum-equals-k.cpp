// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;
//         for(int i = 0;i < nums.size();i++){
//             int sum = 0;
//             // i chooses the starting point.
//             // j chooses the ending point.
//             // sum   = "Does this subarray equal k?"
//             // count = "How many such subarrays did I find?"
//             for(int j = i; j < nums.size();j++){
//                 sum += nums[j];
//                 if(sum == k){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
   
// };



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};