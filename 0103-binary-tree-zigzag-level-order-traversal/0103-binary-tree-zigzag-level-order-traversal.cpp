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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (root == NULL)
            return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        vector<int> tp;
        bool flag = 1;

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            
            if (temp)
            {
                tp.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if (!q.empty())
            {
                if (flag) {
                    ans.push_back(tp);
                    flag = 0;
                }
                else {
                    reverse(tp.begin(), tp.end());
                    ans.push_back(tp);
                    flag = 1;
                }
                tp.clear();
                q.push(NULL);
            }
            else
            {
                if (!flag) {
                    reverse(tp.begin(), tp.end());
                }
                ans.push_back(tp);
                tp.clear();
            }
        }
        return ans;
    }
};
