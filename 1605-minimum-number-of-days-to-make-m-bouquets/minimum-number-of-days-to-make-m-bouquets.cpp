class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalflowers =1ll*m*k;
        int ans = -1;
        int n = bloomDay.size();
        if(totalflowers > n){
                return -1;
            }
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());;
        while(low <= high){
            int mid = low + (high - low)/2;
            int count = 0;
            int bouquets = 0;
            for(int i = 0; i < n; i++){
                if(bloomDay[i] <= mid){
                    count++;
                    if(count == k){
                        bouquets++;
                        count = 0;
                    }
                }
                else{
                    count = 0;
                }
            }  
            if(bouquets >= m){
                ans = mid;
                high = mid-1;
            } 
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};