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
    TreeNode* utility(int start,int end,vector<int>&nums){
        //base case
        if(start>end)return NULL;
        //recursive case
        int k=(start);
        for(int i=start;i<=end;i++){
          if(nums[i]>nums[k])k=i;
        }
        
        TreeNode* root=new TreeNode(nums[k]);
        root->left=utility(start,k-1,nums);
        root->right=utility(k+1,end,nums);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1;
        
       return utility(start,end,nums);
        
        
        
    }
};