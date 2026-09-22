class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low < high){
            int mid = low + (high - low)/2;
            int total = 0;
            for(int i = 0; i < nums.size();i++){
                int remain = (nums[i] + mid - 1) / mid;
                total += remain;
            }
            if(total <= threshold){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};