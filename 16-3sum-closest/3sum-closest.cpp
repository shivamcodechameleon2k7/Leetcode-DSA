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


/*Approach: Sorting + Two Pointers
1. Sort the array using sort(nums.begin(), nums.end()).
2. Initialize clossum with the sum of the first three elements.
3. Use a for loop to fix the first element at index i.
4. Initialize start = i + 1.
5. Initialize end = nums.size() - 1.
6. Run a while loop while start < end.
7. Calculate sum = nums[i] + nums[start] + nums[end].
8. Compare abs(sum - target) with abs(clossum - target). Update clossum if the current sum is closer.
9. If sum < target, increment start; if sum > target, decrement end.
10. If sum == target, return sum immediately. After both loops finish, return clossum.*/