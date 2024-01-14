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
    vector<int> dfs(TreeNode* root){
        
        //base case
        if(!root)return {-1,-1,-1};
        
        //recursive case
        
        vector<int> lst= dfs(root->left);
        vector<int> rst= dfs(root->right);
        
        int res= max({max(lst[1],rst[0])+1,lst[2],rst[2]});
        
        return {lst[1]+1,rst[0]+1,res};
    }
    int longestZigZag(TreeNode* root) {
        
        auto res= dfs(root);
        return res[2];
    }
};