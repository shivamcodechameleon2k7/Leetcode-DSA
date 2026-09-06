class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int appear = 0;
        for (int i : nums){
            appear = appear^i;
        }
        return appear;
        
    }
};