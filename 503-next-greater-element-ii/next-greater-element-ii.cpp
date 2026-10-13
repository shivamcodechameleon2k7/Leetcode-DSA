class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        int n = nums.size();

        /*2 * n — simulates two passes.i % n — handles circular traversal.*/
        for(int i = 0; i < 2 * n;i++){
            int index = i % n;
            while(!st.empty() && nums[st.top()] < nums[index]){
                ans[st.top()] = nums[index];
                st.pop();
            }

            // The condition checks whether we're still in the first pass through the array.
            // If true, the current index is pushed onto the stack.
            // If false, we don't push anything.
            if(i < n){
                st.push(index);
            }
        }
        return ans;
    }
};