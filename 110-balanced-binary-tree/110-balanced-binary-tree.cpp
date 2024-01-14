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
    bool utility(TreeNode* root)
    {
        //base case
        if(!root)return true;
        //recursive case
    if(abs((height(root->left)-height(root->right)))<=1 and utility(root->left) and utility(root->right))
    {
        return true;
    }
        else
        {
            return false;
        }
    }
    bool isBalanced(TreeNode* root) {
      return utility(root);
        
    }
};