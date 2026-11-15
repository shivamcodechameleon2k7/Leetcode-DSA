class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int even = 1;
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < arr.size();i++){
            sum += arr[i];
            if(sum % 2 != 0){
            ans += even;
            odd++;
            }
            else{
                ans += odd;
                even++;
            }
            ans = ans % (1000000007);
        }  
        return ans; 
    }
};