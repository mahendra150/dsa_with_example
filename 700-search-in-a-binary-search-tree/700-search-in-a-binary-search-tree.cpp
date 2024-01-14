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
    TreeNode* utility(TreeNode* root,int val)
    {
        //base case
        if(!root)return NULL;
        //recursive case
        if(root->val==val)return root;
        if(val<root->val)
        {
            return utility(root->left,val);
        }
            return utility(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
       return utility(root,val);
        
    }
};