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
    int sumNumbers(TreeNode* root) {
        return helper(root, "");
    }
    
    int helper(TreeNode* root, string s) {
        if (root == NULL)
            return 0;
        
        s += to_string(root->val);
        
        if (root->left == NULL && root->right == NULL)
            return stoi(s);
        
        return helper(root->left, s) + helper(root->right, s);
    }
};