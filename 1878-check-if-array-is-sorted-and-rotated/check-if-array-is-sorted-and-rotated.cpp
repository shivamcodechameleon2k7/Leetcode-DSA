class Solution {
public:
    bool check(vector<int>& nums) {
    //     int count = 0;
    //     for(int i = 0; i < nums.size();i++){
    //         if(nums[i] > nums[(i+1)%nums.size()]){
    //             count++;
    //         }
    //     }
    //     return count<=1;  
    // }

        bool found = false;

        for(int i = 0; i < nums.size(); i++) {
            int next = (i + 1) % nums.size();

            if(nums[i] > nums[next]) {
                if(found) {
                    return false;
                }
                found = true;
            }
        }

        return true;
    }
};