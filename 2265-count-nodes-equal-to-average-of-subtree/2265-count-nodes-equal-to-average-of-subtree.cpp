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
    int count;
    vector<int> dfs(TreeNode* root){
        
        //base case
        if(!root)return {0,0};
        if(!root->left and !root->right){
            count+=1;
            return {root->val,1};
        }
        
        //recursive case
        
        auto left= dfs(root->left);
        auto right= dfs(root->right);
        
        auto leftSum= left[0];
        auto leftCount= left[1];
        auto rightSum= right[0];
        auto rightCount= right[1];
        
        auto sum= leftSum + rightSum + root->val;
        auto nodeCount= leftCount + rightCount + 1;
        
        int average= (sum)/(nodeCount);
        if(average==root->val)count+=1;
        
        return {sum,nodeCount};
    }
    int averageOfSubtree(TreeNode* root) {
        
        count=0;
        dfs(root);
        
        return count;
    }
};