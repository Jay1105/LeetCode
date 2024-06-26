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
    bool helper (TreeNode* root, long long l, long long r) {
        if (root == NULL)
            return true;
        
        if (root->val > l && root->val < r) {
            return helper(root->left, l, root->val) && helper(root->right, root->val, r);
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        long long l = -10000000000;
        long long r = 10000000000;
        
        if (helper(root, l, r))
            return true;
        
        return false;
    }
};