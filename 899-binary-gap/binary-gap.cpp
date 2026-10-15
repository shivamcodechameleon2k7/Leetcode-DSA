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
/*pos tracks the current binary digit's position.
prev stores the position of the previous 1. Initially, -1 means we haven't found one.
n % 2 == 1 checks whether the current binary digit is 1.
If we've already found a 1, calculate pos - prev and update ans if the distance is greater.
Divide n by 2 to move to the next binary digit.*/