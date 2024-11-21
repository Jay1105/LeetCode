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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        int sum = 0;
        int mxsum = INT_MIN;
        int ans = 0;
        int cnt = 0;
        
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            
            if (curr != NULL)
            {
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            
                sum += curr->val;
            }
            else 
            {
                cnt++;
                if (sum > mxsum)
                {
                    mxsum = sum;
                    ans = cnt;
                }
                sum = 0;
        
                if (!q.empty())
                    q.push(NULL);
            }
        }
        return ans;
    }
};
