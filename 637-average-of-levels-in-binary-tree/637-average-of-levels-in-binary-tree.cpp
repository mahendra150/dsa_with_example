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
        queue<TreeNode*>q;
        q.push(root);
        vector<double>nums;
        while(!q.empty())
        {
            int n=q.size();
            double size=n;
            double ans=0;
            while(n--)
            {
                auto x=q.front();
                q.pop();
                if(x)
                {
                    ans+=double(x->val);
                    if(x->left)q.push(x->left);
                    if(x->right)q.push(x->right);
                }
                
            }
            ans/=size;
            nums.push_back(ans);
        }
        return nums;
        
    }
};