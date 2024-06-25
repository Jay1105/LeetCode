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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        double sum = 0;
        double cnt = 0;
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            if (temp) {
                sum += temp->val;
                cnt++;
                
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if (!q.empty()) {
                double avgg = sum / cnt;
                ans.push_back(avgg);
                sum = 0, cnt = 0;
                
                q.push(NULL);
            }
            else {
                double avgg = sum / cnt;
                ans.push_back(avgg);
                sum = 0, cnt = 0;
            }
        }
        
        return ans;
    }
};