class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);        
        int maxval = nums[0];
        int minval = nums[n-1];
        for(int i = 0; i < nums.size(); i++){
            maxval = max(maxval,nums[i]);
            prefix[i] = maxval;
            }
        for(int i = nums.size()-1 ;i  >= 0;i--){
            minval = min(minval, nums[i]);
            suffix[i] = minval;
            }
        for(int i = 0; i < n; i++){
            if(prefix[i] - suffix[i] <= k){
                return i;
            }
        } 
        return -1;
    } 
};
