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
    TreeNode* dfs(int preStart,int preEnd,int postStart,int postEnd,vector<int> &preorder,vector<int> &postorder){
        
        //base case
        if(preStart>preEnd)return NULL;
        
        //recursive case
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        if(preStart==preEnd)return root;
        
        int postIndex= postStart;
        while(preorder[preStart+1] != postorder[postIndex]){
            postIndex++;
        }
        
        int len= (postIndex-postStart) + 1;
        
        root->left= dfs(preStart+1,preStart+len,postStart,postIndex,preorder,postorder);
        root->right= dfs(preStart+len+1,preEnd,postIndex+1,postEnd-1,preorder,postorder);
        
        return root;
        
        
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        return dfs(0,preorder.size()-1,0,postorder.size()-1,preorder,postorder);
    }
};