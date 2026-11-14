/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        if(nums.empty()){
            return NULL;
        }

        int maxi = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[maxi]){
                maxi = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxi]);

        vector<int> left(nums.begin(), nums.begin() + maxi);
        vector<int> right(nums.begin() + maxi + 1, nums.end());

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;
    }
};


/*
Follow these steps:
1. Find the maximum element in the array.
2. Create a new tree node using that maximum element.
3. Elements on the left side of the maximum become the left subtree.
4. Elements on the right side become the right subtree.
5. Recursively repeat the same process for both subarrays.
6. Return the root node.};*/