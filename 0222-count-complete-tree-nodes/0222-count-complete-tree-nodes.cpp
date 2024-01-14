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
    int dfs(TreeNode* root){
        //base case
        if(!root)return 0;
        //recursive case
        int lh=0;
        int rh=0;
        TreeNode* l=root;
        TreeNode* r=root;
        
        while(l){
            l=l->left;
            lh++;
        }
        while(r){
            r=r->right;
            rh++;
        }
        
        //Condition for F.B.T
        if(lh==rh)return pow(2,lh)-1;
        
        
        return dfs(root->left) + dfs(root->right) + 1;
    }
    int countNodes(TreeNode* root) {
        
       return dfs(root);
        
    }
};