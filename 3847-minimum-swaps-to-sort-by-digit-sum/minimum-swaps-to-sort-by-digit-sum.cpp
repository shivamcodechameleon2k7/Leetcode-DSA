
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end(), [&](auto a, auto b) {
            int sumA = digitSum(a.first);
            int sumB = digitSum(b.first);

            if (sumA != sumB)
                return sumA < sumB;

            return a.first < b.first;
        });
        vector<int> visited(n, 0);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i)
                continue;
            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = 1;
                j = arr[j].second;
                cycleSize++;
            }

            if (cycleSize > 1)
                swaps += cycleSize - 1;
        }
        return swaps;
    }
};


/*1. digitSum(int n) calculates the sum of digits using n % 10 to get the last digit and n /= 10 to remove it.
2. int n = nums.size(); stores the number of elements in the array.
3. vector<pair<int,int>> arr; stores each number with its original index, like {38, 0}.
4. The for loop copies every number and its original index into arr.
5. sort() sorts numbers by ascending digit sum. If digit sums are equal, the smaller number comes first.
6. vector<int> visited(n, 0); tracks which positions have already been processed, while swaps counts the swaps needed.
7. The if condition skips positions that are already visited or whose element is already in its correct position.
8. The while loop detects cycles by following original indices using j = arr[j].second, marking positions visited and counting the cycle size.
9. swaps += cycleSize - 1; calculates the minimum swaps for each cycle. A cycle of size 3 requires 2 swaps.
10. return swaps; returns the total minimum swaps required to sort the array according to the digit-sum rules.
Complexity: Time \(O(n\log n)\), space \(O(n)\)*/

