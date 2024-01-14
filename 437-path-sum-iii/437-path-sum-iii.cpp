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
    void utility(TreeNode* root,int prefixSum,unordered_map<int,int>h,int &count,int targetSum){
        //base case
        if(!root)return;
        //recursive case
        prefixSum+=root->val;
        if(h.count(prefixSum-targetSum)>0)count+=h[prefixSum-targetSum];
        h[prefixSum]++;
        
        utility(root->left,prefixSum,h,count,targetSum);
        utility(root->right,prefixSum,h,count,targetSum);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        int prefixSum=0;
        int count=0;
        unordered_map<int,int>h;
        h[0]++;
        utility(root,prefixSum,h,count,targetSum);
        return count;
        
    }
};