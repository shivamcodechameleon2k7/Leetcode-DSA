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
    int count = 0;
    int ans = 0;

    void inorder(TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, k);

        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};



/*
1. count tracks the number of visited nodes.
2. ans stores the kth smallest value.
3. If root == NULL, stop recursion.
4. First traverse the left subtree.
5. Increment count when visiting the current node.
6. If count == k, store root->val in ans.
7. Otherwise, traverse the right subtree.
8. Finally, return ans.*/
