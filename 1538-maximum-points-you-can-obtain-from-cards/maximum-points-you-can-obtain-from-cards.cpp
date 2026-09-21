class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // the right-side sum
        int rightsum = 0;

        // n stores the total number of cards.
        int n = cardPoints.size();

        //sum of the last k cards

        for(int i = n-1; i >= n-k; i--){
            rightsum += cardPoints[i];
        }

        // Store the initial maximum score
        int maxscore = rightsum;

        // Initialize the left-side sum
        int leftsum = 0;

        // This points to the first right-side card that will be removed when we start taking cards from the left.
        int rightindex = n-k;

        //  process k times,Each iteration changes the combination:
        for(int i = 0;i < k; i++){

        // Add one card from the left and remove one from the right,
        // So we are effectively replacing one right card with one left card.
            leftsum += cardPoints[i];
            rightsum -= cardPoints[rightindex];


 
        //the right index and update the maximum,
        // We check the score after every possible combination and keep the largest one.         
            rightindex++;
            maxscore = max(maxscore,leftsum + rightsum);
        }

        // maximum score
        // After checking all k + 1 possible left/right combinations, maxScore contains the answer.
        return maxscore;
    }
};