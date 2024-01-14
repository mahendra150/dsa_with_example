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
    bool utility(TreeNode* p,TreeNode* q)
    {
        //base case
        if(!p or !q)return p==q;
        //recursive case
        if(p->val==q->val and utility(p->left,q->left) and utility(p->right,q->right))return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return utility(p,q);
        
    }
};