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
    vector<int> ans;
    void prehelp(TreeNode *root)
    {
        if (root != NULL)
        {
            ans.push_back(root->val);
            prehelp(root->left);
            prehelp(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        prehelp(root);
        
        return ans;
    }
};