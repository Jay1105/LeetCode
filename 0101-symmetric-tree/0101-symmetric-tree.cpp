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
    bool isMirror(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL)
            return true;
        else if (p == NULL || q == NULL)
            return false;
        
        if (p->val == q->val)
            return isMirror(p->left, q->right) && isMirror(p->right, q->left);
        
        return false;
    }

    bool isSymmetric(TreeNode* root) 
    {
        if (root->left == NULL && root->right == NULL)
            return true;
        else if (root->left == NULL || root->right == NULL)
            return false;
        
        return isMirror(root->left, root->right);
    }
};
