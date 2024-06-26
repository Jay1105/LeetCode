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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode *temp = root;
        
        if (root->left) {
            temp = temp->left;
            
            while (temp->right)
                temp = temp->right;
            
            ans = min(ans, root->val - temp->val);
            int left = getMinimumDifference(root->left);
            ans = min(ans, left);
        }
        
        temp = root;
        if (root->right) {
            temp = temp->right;
            
            while (temp->left)
                temp = temp->left;
            
            ans = min(ans, temp->val - root->val);
            int right = getMinimumDifference(root->right);
            ans = min(ans, right);
        }
        
        return ans;
    }
};