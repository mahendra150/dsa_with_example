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
    void utility(TreeNode* root,TreeNode* &prev,int &minVal){
        //base case
        if(!root)return;
        //recursive case
        utility(root->left,prev,minVal);
        
        if(prev){
            minVal=min(minVal,abs(root->val-prev->val));
        }
        prev=root;
        
        utility(root->right,prev,minVal);
    }
    int getMinimumDifference(TreeNode* root) {
        int minVal=INT_MAX;
        TreeNode* prev=NULL;
        utility(root,prev,minVal);
        
        return minVal;
        
    }
};