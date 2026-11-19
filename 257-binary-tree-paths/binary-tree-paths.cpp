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
    void solve(TreeNode* root, string path, vector<string>& ans) {

        if(root == NULL){
            return;
        }

        path += to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }

        path += "->";

        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;

        solve(root, "", ans);

        return ans;
    }
};
/*1. string path builds one root-to-leaf path.
2. vector<string>& ans stores all completed paths.
3. solve() explores both left and right subtrees.
Time Complexity: \(O(N \times H)\) in the general case, where \(N\) is the number of nodes and \(H\) is the tree height, accounting for path-string copying.*/