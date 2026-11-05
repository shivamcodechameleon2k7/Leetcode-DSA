class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for(int i = 0; i < arr1.size(); i++) {
            bool valid = true;

            for(int j = 0; j < arr2.size(); j++) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    valid = false;
                    break;
                }
            }

            if(valid){
                count++;
            }
        }

        return count;
    }
};

/*Initialize count = 0 to store the answer.
Use the outer loop to select each element from arr1.
Use the inner loop to compare it with every element of arr2.
If abs(arr1[i] - arr2[j]) <= d, mark it invalid and break the inner loop.
If no element in arr2 violates the condition, increase count.*/