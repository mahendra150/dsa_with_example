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
    void utility(TreeNode* root,vector<int>&ans)
    {
        //base case
        if(!root)return;
        //recursive case
        ans.push_back(root->val);
        utility(root->left,ans);
        utility(root->right,ans);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        utility(root,ans);
        return ans;
        
    }
};