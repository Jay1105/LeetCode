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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        int tp;
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            if (temp) {
                tp = temp->val;
                
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if (!q.empty()) {
                ans.push_back(tp);
                q.push(NULL);
            }
            else {
                ans.push_back(tp);
            }
        }
        
        return ans;
    }
};