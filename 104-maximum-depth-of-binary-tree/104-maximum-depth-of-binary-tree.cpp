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
    int utility(TreeNode* root)
    {
        //base case
        if(!root)return 0;
        //recursive case
        return max(utility(root->left),utility(root->right))+1;
    }
    int maxDepth(TreeNode* root) {
       return utility(root);
        
    }
};