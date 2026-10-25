class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int clossum = nums[0]+nums[1]+nums[2];
        for(int i = 0;i < nums.size()-2;i++){
            int start = i+1;
            int end = nums.size()-1;
            while(start < end){
                sum = nums[i]+nums[start]+nums[end];
                if(abs(sum-target) < abs(clossum-target)){
                    clossum = sum;
                }
                if(sum < target){
                    start++;
                }
                else if(sum > target){
                    end--;
                }
                else{
                    return sum;
                }
            }
        }
        return clossum;
    }
};