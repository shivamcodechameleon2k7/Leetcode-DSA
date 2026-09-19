class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        // maximum of vector data is found using above code snippet
        int n = piles.size();
        while (low <= high){
            int mid = low + (high - low)/2;
            long long totalhours = 0;
            // to prevent overflow long long is used
            for(int i = 0; i < n; i++){
                // ceiling-division formula
                int hours = (piles[i] + mid - 1)/mid;
                totalhours = totalhours + hours;
            }
            if(totalhours <= h){
                    high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    
};