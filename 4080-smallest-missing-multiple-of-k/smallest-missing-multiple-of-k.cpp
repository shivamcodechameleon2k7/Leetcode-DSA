class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i = 1;
        int j = 0;
        int candidate;
        bool found;
        while(true){
            candidate  = k*i;
            found = false;
            j=0;
            while( j < nums.size()){
                if(nums[j] == candidate){
                    found = true;
                    break; 
                }
                j++;
            }
            if (found){
                i++;
            }
            else{
                return candidate;
            } 
        }
    }
};