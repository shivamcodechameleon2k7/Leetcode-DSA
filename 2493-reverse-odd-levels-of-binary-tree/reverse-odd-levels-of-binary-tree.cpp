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


/*Base Case: If root == NULL, return NULL.

2. Initialize Queue: Create queue<TreeNode*> q and push the root.

3. Initialize Level: Set level = 0, because the root belongs to level 0.

4. Create Vector: Create vector<TreeNode*> nodes to store pointers of nodes at the current level.

5. Start BFS: Run while(!q.empty()) to traverse the tree.

6. Calculate Level Size: Store q.size() in size to know how many nodes belong to the current level.

7. Process Nodes: Run while(size > 0) to process exactly the current level's nodes.

8. Get Current Node: Use q.front() to access the first node and q.pop() to remove it.

9. Store Node: Use nodes.push_back(curr) to store the current node pointer.

10. Add Children: Push the left and right children into the queue if they are not NULL.

11. Decrease Size: Use size-- after processing each node.

12. Check Odd Level: After the inner loop, check level % 2 != 0.

13. Reverse Values: If the level is odd, use two pointers:
- i = 0
- j = nodes.size() - 1
- Swap nodes[i]->val and nodes[j]->val.
- Increment i and decrement j.
- Continue while i < j.
14. Clear Vector: Use nodes.clear() to remove pointers from the previous level.

15. Increment Level: Use level++ to move to the next level.

16. Return: Return the modified root.*/