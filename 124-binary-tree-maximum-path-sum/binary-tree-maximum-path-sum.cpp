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
class Solution{
public:
    int maxi = INT_MIN;

    int maxPath(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        int leftSum = max(0, maxPath(root->left));
        int rightSum = max(0, maxPath(root->right));

        maxi = max(maxi, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxi;
    }
};



/*
1. maxi = INT_MIN
- Stores the maximum path sum found so far.
- Starts with the smallest possible integer.

2. Base case
- If root == NULL, return 0.

3. Calculate left sum
- Recursively calculate the maximum path sum from the left subtree.
- max(0, ...) ignores a negative contribution.

4. Calculate right sum
- Recursively calculate the maximum path sum from the right subtree.
- Again, ignore negative contributions.

5. Update maximum path sum
- root->val + leftSum + rightSum
- This considers a path passing through the current node and including both children.

6. Return maximum contribution
- root->val + max(leftSum, rightSum)
- Return only one side because a path extending to the parent cannot branch into both children.

7. Final answer
- Return maxi.
Complexity analysis
- Time Complexity: \(O(N)\) — Every node is visited once.
- Space Complexity: \(O(H)\) — Recursive call stack, where H is the tree height.

Important concept
Why do we use two different calculations?
- leftSum + rightSum + root->val → Updates the global maximum.
- max(leftSum, rightSum) + root->val → Returns the contribution to the parent.

We use 0 because we don't want a negative subtree contribution to reduce our path sum.
Look at this:
int leftSum = max(0, maxPath(root->left));
max(a, b) returns the greater value.
*/