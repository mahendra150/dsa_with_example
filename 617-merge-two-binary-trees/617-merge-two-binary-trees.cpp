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
    TreeNode* utility(TreeNode* root1,TreeNode* root2)
    {
        //base case
        if(!root1 and !root2)return NULL;
        //recursive case
         TreeNode* root=NULL;
        if(root1 and root2)
        {
            root=new TreeNode(root1->val + root2->val);
            root->left=utility(root1->left,root2->left);
            root->right=utility(root1->right,root2->right);
        }
        else if(root1 and !root2)
        {
            root=new TreeNode(root1->val);
            root->left=utility(root1->left,root2);
            root->right=utility(root1->right,root2);
        }
        else if(!root1 and root2)
        {
            root=new TreeNode(root2->val);
            root->left=utility(root1,root2->left);
            root->right=utility(root1,root2->right);
        }
        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
       return utility(root1,root2);
        
    }
};