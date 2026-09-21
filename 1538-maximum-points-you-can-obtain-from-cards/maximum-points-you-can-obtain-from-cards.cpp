class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int rightsum = 0;
        int n = cardPoints.size();
        for(int i = n-1; i >= n-k; i--){
            rightsum += cardPoints[i];
        }
        int maxscore = rightsum;
        int leftsum = 0;
        int rightindex = n-k;
        for(int i = 0;i < k; i++){
            leftsum += cardPoints[i];
            rightsum -= cardPoints[rightindex];
            rightindex++;
            maxscore = max(maxscore,leftsum + rightsum);
        }
        return maxscore;
    }
};