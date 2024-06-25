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
    long mx = INT_MIN;
    
    long helper(TreeNode* root) {
        if (root == NULL)
            return INT_MIN;
        
        long left = helper(root->left);
        long right = helper(root->right);
        
        long closed = left + right + root->val;
        long path = root->val + max(left, right);
        
        mx = max(max((long)root->val, mx), max(closed, path));
        
        return max((long)root->val, path);
    }

    long maxPathSum(TreeNode* root) {
        long tp = helper(root);
        return mx;
    }
};
