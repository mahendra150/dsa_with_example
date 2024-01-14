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
    int dfs(TreeNode* root,int &res){
        //base case
        if(!root)return 0;
        
        //recursive case
        
        int leftPath=dfs(root->left,res);
        int rightPath=dfs(root->right,res);
        
        int leftCheck=0,rightCheck=0;
        
        if(root->left and root->val==root->left->val){
            leftCheck=leftPath+1;
        }
        
        if(root->right and root->val==root->right->val){
            rightCheck=rightPath+1;
        }
        
        res=max(res,leftCheck+rightCheck);
        
        return max(leftCheck,rightCheck);
    }
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        
        dfs(root,res);
        
        return res;
        
        
    }
};