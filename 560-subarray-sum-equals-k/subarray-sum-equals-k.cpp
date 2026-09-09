class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0 ; i < nums.size();i++){
            int sum = 0;
            // i chooses the starting point.
            // j chooses the ending point.
            // sum   = "Does this subarray equal k?"
            // count = "How many such subarrays did I find?"
            for(int j = i; j < nums.size();j++){
                sum += nums[j];
                if(sum == k){
                    count++;
                }
            }
        } 
        return count;  
    }
};