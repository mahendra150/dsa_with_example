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
     bool dfs(TreeNode* root,int target,string &path){
         
         //base case
         if(!root)return false;
         
         //recursive case
         
         if(root->val==target)return true;
         
         auto left= dfs(root->left,target,path);
         auto right= dfs(root->right,target,path);
         
         if(left){
             
             path+= "L";
             return true;
         }
         if(right){
             
             path+= "R";
             return true;
         }
         
         return false;
     }   
     TreeNode* LCA(TreeNode* root,int source,int dest){
         
         //base case
         if(!root)return NULL;
         
         //recursive case
         
         if(root->val==source or root->val==dest)return root;
         
         auto left= LCA(root->left,source,dest);
         auto right= LCA(root->right,source,dest);
         
         if(left and right)return root;
         
         if(left and !right)return left;
         
         return right;
     }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        auto lca= LCA(root,startValue,destValue);
        
        string path="";
        dfs(lca,startValue,path);
        auto distFromLCAToSource=path;
        
        for(int i=0;i<path.size();i++)distFromLCAToSource[i]='U';
        
        path="";
        dfs(lca,destValue,path);
        
        auto distFromLCAToDest=path;
        reverse(distFromLCAToDest.begin(),distFromLCAToDest.end());
        
        return distFromLCAToSource + distFromLCAToDest;
    }
};