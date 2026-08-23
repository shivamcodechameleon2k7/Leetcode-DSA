class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
    int compliment;
    for(int i = 0;i< nums.size();i++){
        compliment = target - nums[i];
        for(int j = i+1; j< nums.size();j++){
            if(nums[j]==compliment){
                return vector<int>{i, j};
                }
            }
        
        } 
        return {};
    }
};