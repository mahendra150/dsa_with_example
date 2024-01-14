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
    int height(TreeNode* root)
    {
        //base case
        if(!root)return 0;
        //recursive case
        return max(height(root->left),height(root->right))+1;
    }
    int utility(TreeNode* root)
    {
        //base case
        if(!root)return 0;
        //recursive case
        int opt1=height(root->left)+height(root->right);
        int opt2=utility(root->left);
        int opt3=utility(root->right);
        return max({opt1,opt2,opt3});
    }
    int diameterOfBinaryTree(TreeNode* root) {
       return utility(root);
        
    }
};