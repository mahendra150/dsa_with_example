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
        if(p->val<root->val and q->val < root->val)
        {
            return utility(root->left,p,q);
        }
        if(p->val > root->val and q->val > root->val)
        {
            return utility(root->right,p,q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return utility(root,p,q);
        
    }
};