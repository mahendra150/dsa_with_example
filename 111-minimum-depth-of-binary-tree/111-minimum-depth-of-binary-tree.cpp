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
    void utility(TreeNode* root,int level,int &ans)
    {
        //base case
        if(!root)return;
        //recursive case
        level+=1;
        if(!root->left and !root->right)ans=min(ans,level);
        utility(root->left,level,ans);
        utility(root->right,level,ans);
    }
    int minDepth(TreeNode* root) {
        int level=0;
        if(!root)return 0;
       int ans=INT_MAX;
        utility(root,level,ans);
        return ans;
        
    }
};