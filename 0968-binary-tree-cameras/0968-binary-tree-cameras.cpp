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
    map<pair<TreeNode*,pair<bool,bool>>,int> dp;
    
    int dfs(TreeNode* root,int placeCam,int parentCam){
        //base case
        
        if(!root){
            
            if(placeCam)return 1e9;
            else return 0;
        }
        //Leaf Node
        if(!root->left and !root->right){
            
            if(placeCam){
                return 1;
            }
            else{
                
                if(parentCam)return 0;
                else return 1e9;
            }
        }
        //recursive case
        if(dp.find({root,{placeCam,parentCam}}) != dp.end())return dp[{root,{placeCam,parentCam}}];
        
        // TreeNode* c1= root->left;
        // TreeNode* c2= root->right;
        
        if(placeCam){
            
            return dp[{root,{placeCam,parentCam}}]= 1 + min( dfs(root->left,1,1), dfs(root->left,0,1) ) +                                                        min( dfs(root->right,1,1), dfs(root->right,0,1) );
        }
        else{
            
            if(parentCam){
                
    return dp[{root,{placeCam,parentCam}}]= min( dfs(root->left,1,0), dfs(root->left,0,0) ) +                                                             min( dfs(root->right,1,0), dfs(root->right,0,0) );
            }
            else{
                
                int option1= dfs(root->left,1,0) + min( dfs(root->right,1,0), dfs(root->right,0,0) );
                int option2= dfs(root->right,1,0) + min( dfs(root->left,1,0), dfs(root->left,0,0) );
                
                return dp[{root,{placeCam,parentCam}}]= min(option1,option2);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        
        
        //States of DP --> dp[u][placeCam][parentCam]
        dp.clear();
        
        //FinalAns 
        return min({ dfs(root,1,0), dfs(root,0,0) });
    }
};