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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        queue <TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<TreeNode*> nodes;

        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                TreeNode* curr = q.front();
                q.pop();
                nodes.push_back(curr);

                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
                size--;
                
                
            }
            if(level % 2 != 0){
                int i = 0;
                int j = nodes.size()-1;
                while(i<j){
                    swap(nodes[i]->val,nodes[j]->val);
                    i++;
                    j--;
                }
            }
            nodes.clear();
            level++;
        }
        return root;
    }
};