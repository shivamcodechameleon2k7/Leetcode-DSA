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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        // using swap function ;
        swap(root->left,root->right);

        // using swap through a temp variable;
        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;


        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

/*Check if the node is NULL.
Swap its left and right children.
Recursively invert the left subtree.
Recursively invert the right subtree.
Return the root.*/