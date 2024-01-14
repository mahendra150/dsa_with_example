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
    TreeNode* dfs(TreeNode* root,int level,int val,int depth){
        
        //base case
        if(depth==1){
            
            TreeNode* newNode= new TreeNode(val);
            newNode->left= root;
            root= newNode;
            return root;
        }
        if(!root)return NULL;
        
        //recursive case
        
        if(level+1==depth){
            
            TreeNode* leftNode= root->left;
            TreeNode* rightNode= root->right;
            
            root->left= new TreeNode(val);
            root->right= new TreeNode(val);
            root->left->left= leftNode;
            root->right->right= rightNode;
            
            return root;
        }
        
        root->left= dfs(root->left,level+1,val,depth);
        root->right= dfs(root->right,level+1,val,depth);
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        return dfs(root,1,val,depth);
        
    }
};