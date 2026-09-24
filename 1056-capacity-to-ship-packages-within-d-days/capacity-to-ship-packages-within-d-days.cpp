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

                    //currweight stores how much weight is currently loaded on the current day.
                    //day counts how many new days have been started when the current package doesn't fit:
                    day++;
                    currweight = weights[i];
                }
                else{
                    currweight += weights[i];
                }
            }
            int dayreq = day+1;

            // Compare dayreq with the given days
            if(dayreq <= days){
                high = mid;
            }
            else{
                low = mid+1;
                //The goal is to find the smallest capacity that can ship everything within days; when low == high, return low
            }
        }
        return low;
    } 
};