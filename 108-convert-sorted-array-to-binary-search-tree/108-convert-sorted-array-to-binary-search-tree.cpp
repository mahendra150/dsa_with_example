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
    TreeNode* utility(vector<int>& nums,int s,int e)
    {
        //base case
        if(s>e)return NULL;
        //recursive case
        int mid=(s+e)/2;
      TreeNode* root=new  TreeNode(nums[mid]);
        root->left=utility(nums,s,mid-1);
        root->right=utility(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        return utility(nums,s,e);
        
    }
};