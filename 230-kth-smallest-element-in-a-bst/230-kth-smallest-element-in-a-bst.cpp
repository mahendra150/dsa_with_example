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
    void utility(TreeNode* root,int &k,TreeNode* &ans)
    {
        //base case
        if(!root)return;
        //recursive case
        utility(root->left,k,ans);
        k--;
        if(k==0)
        {
            ans=root;
            return ;
        }
       utility(root->right,k,ans);
        
        
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans;
    utility(root,k,ans);
        return ans->val;
        
    }
};