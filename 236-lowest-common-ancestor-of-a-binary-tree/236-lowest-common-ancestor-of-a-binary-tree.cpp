/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* utility(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        //base case
        if(!root)return NULL;
        //recursive case
        if(root->val==p->val or root->val==q->val)return root;
        TreeNode* left=utility(root->left,p,q);
        TreeNode* right=utility(root->right,p,q);
        if(left and right)
        {
            return root;
        }
        if(left and !right)
        {
            return left;
        }
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return utility(root,p,q);
        
    }
};