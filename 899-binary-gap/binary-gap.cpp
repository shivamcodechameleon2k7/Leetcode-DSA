class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int pos = 0;
        int ans = 0;
        while(n > 0){
            if(n % 2 == 1){
                if(prev != -1){
                    int distance = pos - prev;
                    if(distance > ans){
                        ans = distance;
                    }
                }
                prev = pos;
            }
            n = n / 2;
            pos++;
        }
        return ans;
    }
};