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
    unordered_map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> dfs(int n){
        
        //base case
        
        vector<TreeNode*> ans;
        
        if(n % 2 == 0)return {};
        if(n==1){
            
            TreeNode* newNode = new TreeNode(0,NULL,NULL);
            ans.push_back(newNode);
            return ans;
        }
        //recursive case
        if(dp.find(n) != dp.end())return dp[n];
        
        for(int mid=2;mid<=n;mid+=2){
            
            auto lst= mid-1;
            auto rst= n-mid;
            
            vector<TreeNode*> left= dfs(lst);
            vector<TreeNode*> right= dfs(rst);
            
            for(int i=0;i<left.size();i++){
                
                for(int j=0;j<right.size();j++){
                    
                    TreeNode* node= new TreeNode(0,left[i],right[j]);
                    ans.push_back(node);
                }
            }
        }
    
        
        return dp[n]= ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        
        
        return dfs(n);
    }
};