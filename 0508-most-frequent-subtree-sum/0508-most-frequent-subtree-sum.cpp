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
    unordered_map<int,int> freq;
    int dfs(TreeNode* root){
        
        //base case
        if(!root)return 0;
        
        //recursive case
        
        int left= dfs(root->left);
        int right= dfs(root->right);
        
        freq[left+right+root->val]+=1;
        return left+right+root->val;
        
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root)return {};
        
        dfs(root);
        int max=INT_MIN;
        
        for(auto i:freq){
            
            if(i.second>max){
                max=i.second;
            }
        }
        
        vector<int> res;
        
        for(auto i:freq){
            if(i.second==max)res.push_back(i.first);
        }
        
        return res;
    }
};