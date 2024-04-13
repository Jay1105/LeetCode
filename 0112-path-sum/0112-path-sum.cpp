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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, 0, targetSum);
    }
    
    bool helper(TreeNode* root, int currSum, int targetSum) {
        if (root == NULL) 
            return false;
        
        int temp = currSum + root->val;
        if (targetSum == temp && root->left == NULL && root->right == NULL)
            return true;
        if (helper(root->left, temp, targetSum) || helper(root->right, temp, targetSum))
            return true;
        
        return false;
    }
};