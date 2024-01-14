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
    int res;
    void dfs(TreeNode* root,unordered_map<int,int> &freq){
        
        //base case
        if(!root)return;
        
        //recursive case
        freq[root->val]+=1;
        if(!root->left and !root->right){
            int odd=0;
            for(auto i:freq){
                
                if(i.second %2 != 0){
                    odd+=1;
                }
            }
            
            if(odd<=1)res+=1;
        }
    
        dfs(root->left,freq);
        dfs(root->right,freq);
        
        freq[root->val]-=1;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        unordered_map<int,int> freq;
        res=0;
        dfs(root,freq);
        
        return res;
    }
};