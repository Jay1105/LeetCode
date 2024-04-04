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
    unordered_map<int, int> m;
    
    TreeNode* constructTree(vector<int>& preorder, int& index, int start, int end) 
    {
        if (start > end)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        int pos = m[root->val];
        
        root->left = constructTree(preorder, index, start, pos - 1);
        root->right = constructTree(preorder, index, pos + 1, end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {   
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        
        int index = 0;
        int n = inorder.size();
        TreeNode* res = constructTree(preorder, index, 0, n - 1);
        
        return res;
    }
};