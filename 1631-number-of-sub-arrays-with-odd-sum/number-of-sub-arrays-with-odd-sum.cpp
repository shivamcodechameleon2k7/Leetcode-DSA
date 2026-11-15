class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int even = 1;
        int sum = 0;
        int ans = 0;
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


/*
odd = 0, even = 1 — correct initialization.  odd = 0 because initially there are no odd prefix sums, 
and even = 1 because the empty prefix sum is 0, which is even.

Calculate running prefix sum.
If prefix sum is odd:
- Add even to ans.
- Increment odd.
Otherwise:
- Add odd to ans.
- Increment even.
Apply modulo. -> Keeps the answer within the required modulo.
(Since the answer can be very large, return it modulo 109 + 7.)
Return answer.
*/