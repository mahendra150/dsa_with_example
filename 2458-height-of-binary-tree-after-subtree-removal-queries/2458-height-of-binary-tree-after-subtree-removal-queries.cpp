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
    vector<int> tour;
    unordered_map<int,int> h,first,last;
    vector<int> leftMax,rightMax;
    
    void dfs(TreeNode* root,int depth){
        
        //base case
        if(!root)return;
        
        //recursive case
        
        h[root->val]= depth;
        first[root->val]= tour.size();
        
        tour.push_back(root->val);
        
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
        
        last[root->val]= tour.size();
        
        tour.push_back(root->val);
        
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        dfs(root,0);
        
        int n= tour.size();
        leftMax.resize(n,0);
        rightMax.resize(n,0);
        
        leftMax[0]= h[tour[0]];
        for(int i=1;i<n;i++){
            
            leftMax[i]=max(leftMax[i-1],h[tour[i]]);
        }
        
        rightMax[n-1]= h[tour[n-1]];
        for(int i=n-2;i>=0;i--){
            
            rightMax[i]=max(rightMax[i+1],h[tour[i]]);
        }
        
        vector<int> res;
        for(auto q:queries){
            
            auto left= first[q]-1;
            auto right= last[q]+1;
            
            auto subRes= max(leftMax[left],rightMax[right]);
            res.push_back(subRes);
        }
        
        return res;
    }
};