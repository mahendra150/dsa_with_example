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
    int utility(TreeNode* root,int &maxSum)
    {
        //base case
        if(!root)return 0;
        //recursive case
        int left=max(0,utility(root->left,maxSum));
        int right=max(0,utility(root->right,maxSum));
        maxSum=max(maxSum,root->val+left+right);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
       utility(root,maxSum);
        return maxSum;
        
    }
};