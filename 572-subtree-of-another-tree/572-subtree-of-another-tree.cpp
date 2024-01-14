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
    bool isSameTree(TreeNode* p,TreeNode* q){
        //base case
        if(!p or !q)return p==q;
        //recursive case
        if(p->val==q->val and isSameTree(p->left,q->left) and isSameTree(p->right,q->right))return true;
            return false;
    }
    bool utility(TreeNode* root,TreeNode* subRoot){
        //base case
        if(!root)return false;
        //recursive case
        if(isSameTree(root,subRoot))return true;
        
       bool left= utility(root->left,subRoot);
       bool right= utility(root->right,subRoot);
       
        return left or right;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return utility(root,subRoot);
        
    }
};