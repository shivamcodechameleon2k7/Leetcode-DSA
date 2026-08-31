class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    //     int k = 0;
    //     for(int i = 0;i<nums.size();i++){
    //         if(nums[i] != val){
    //             nums[k] = nums[i];
    //             k++;
    //         }
           
    //     }
    //     return k;  
    // }
   
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right]; 
                right--;                  
            } else {
                left++;
            }
        }
        return left;
    }
};

