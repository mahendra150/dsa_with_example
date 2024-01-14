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
    TreeNode* utility(vector<int>& preorder,int &i,int &max)
    {
        //base case
        if(i==preorder.size()  or preorder[i]>max)return NULL;
        //recursive case
      TreeNode* root=new TreeNode(preorder[i++]);
        root->left=utility(preorder,i,root->val);
        root->right=utility(preorder,i,max);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int max=INT_MAX;
         return utility( preorder,i,max);
        
    }
};