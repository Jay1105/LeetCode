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
    unordered_map<int, int> mp;
    
    TreeNode* construct(vector<int>& postorder, int& index, int i, int j)
    {
        if (i > j)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[index--]);
        int pos = mp[root->val];
        
        root->right = construct(postorder, index, pos + 1, j);
        root->left = construct(postorder, index, i, pos - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        
        int index = n - 1;
        return construct(postorder, index, 0, n - 1);
    }
};