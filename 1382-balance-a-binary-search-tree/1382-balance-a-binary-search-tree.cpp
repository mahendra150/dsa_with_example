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
    vector<int> nums;
    
    TreeNode* sortedArrayToBst(int start,int end){
        
        //base case
        if(start>end)return NULL;
        
        //recursive case
        
        int mid= (start+end)/2;
        
        TreeNode* root= new TreeNode(nums[mid]);
        
        root->left= sortedArrayToBst(start,mid-1);
        root->right= sortedArrayToBst(mid+1,end);
        
        return root;
    }
    void dfs(TreeNode* root){
        
        //base case
        if(!root)return;
        
        //recursive case
        
        dfs(root->left);
        
        nums.push_back(root->val);
        
        dfs(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        dfs(root);
        
        int n= nums.size();
        return sortedArrayToBst(0,n-1);
    }
};