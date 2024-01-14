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
    void utility(TreeNode* root,int &count,int prev){
        //base case
        if(!root)return;
        //recursive case
        if(root->val >=prev)count++;
        prev=max(prev,root->val);
        
        utility(root->left,count,prev);
        utility(root->right,count,prev);
        
    }
    int goodNodes(TreeNode* root) {
        int prev=INT_MIN;
        int count=0;
        utility(root,count,prev);
        
        return count;
        
    }
};