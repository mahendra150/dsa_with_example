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
        if(!root){
            return {0,0};
        }
        //recursive case
        
        vector<int> left= dfs(root->left);
        vector<int> right= dfs(root->right);
        
        // dp --> [rob,dontRob]
        vector<int> dp(2);
        
        //Option1--> Rob
        dp[0]= root->val + left[1] + right[1];
        
        //Option2 --> dontRob
        dp[1]= 0 + max(left[0],left[1]) + max(right[0],right[1]);
        
        return dp;
    }
    int rob(TreeNode* root) {
        
        auto dp= dfs(root);
        
        return max({dp[0],dp[1]});
    }
};