class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxmProfit = 0;
        int minmPrice = prices[0];
        for(int i = 0 ; i < prices.size();i++){
            minmPrice = min(minmPrice,prices[i]);
            int currentProfit = prices[i]-minmPrice;
            if(currentProfit > maxmProfit){
                maxmProfit = currentProfit;  
            }
        }
        return maxmProfit;
    }
};