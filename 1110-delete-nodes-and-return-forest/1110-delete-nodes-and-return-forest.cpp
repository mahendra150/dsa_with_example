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
    TreeNode* dfs(TreeNode* root,unordered_map<int,bool> &map,vector<TreeNode*> &res){
        //base case
        if(!root)return NULL;
        //recursive case
        root->left=dfs(root->left,map,res);
        root->right=dfs(root->right,map,res);
        
        if(map.count(root->val)){
            if(root->left)res.push_back(root->left);
            if(root->right)res.push_back(root->right);
            return NULL;
        }
    
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,bool>map;
        for(auto i:to_delete){
            map[i]=true;
        }
        
        vector<TreeNode*>res;
        
        dfs(root,map,res);
        if(!map.count(root->val))res.push_back(root);
        
        return res;
        
    }
};