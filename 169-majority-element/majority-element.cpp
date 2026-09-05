class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr_cand = 0;
        int count = 0;
        for(int num : nums){
            if(count == 0){
                curr_cand = num;
            }
            if(num == curr_cand){
                count++;
            }
            else{
                count--;
            }
        }
        return curr_cand;  
    }
};