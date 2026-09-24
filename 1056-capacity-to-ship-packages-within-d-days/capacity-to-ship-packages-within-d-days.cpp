class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low < high){
            int mid = low + (high - low)/2;
            int day = 0;
            int currweight = 0;
            for(int i = 0; i < weights.size();i++){
                if(currweight + weights[i] > mid){
                    day++;
                    currweight = weights[i];
                }
                else{
                    currweight += weights[i];
                }
            }
            int dayreq = day+1;
            if(dayreq <= days){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    } 
};