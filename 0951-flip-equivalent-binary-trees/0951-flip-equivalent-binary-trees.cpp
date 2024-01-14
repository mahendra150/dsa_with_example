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
    bool dfs(TreeNode* p,TreeNode* q){
        //base case
        if(!p or !q)return p==q;
        //recursive case
        if(p->val != q->val)return false;
        
        bool option1=dfs(p->left,q->left) and dfs(p->right,q->right);
        bool option2=dfs(p->left,q->right) and dfs(p->right,q->left);
        
        return option1 or option2;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        return dfs(root1,root2);
    }
};