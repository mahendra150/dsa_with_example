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
    unordered_map<string,int> h;
    vector<TreeNode*> res;
    
    string dfs(TreeNode* root){
        
        //base case
        if(!root)return " ";
        
        //recursive case
        
        auto left= dfs(root->left);
        auto right= dfs(root->right);
        
        auto subTree= to_string(root->val) + "," + left + "," + right;
        
        h[subTree]+=1;
        if(h[subTree]==2)res.push_back(root);
        
        return subTree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        dfs(root);
        
        return res;
    }
};