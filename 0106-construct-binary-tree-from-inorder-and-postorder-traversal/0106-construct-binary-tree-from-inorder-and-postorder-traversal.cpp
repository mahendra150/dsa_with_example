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
    TreeNode* utility(int s,int e,vector<int>&inorder,vector<int>&postorder,int &i)
    {
        //base case
        if(s>e)return NULL;
        //recursive case
       TreeNode* root=new TreeNode(postorder[i--]);
        int k=(-1);
        for(int j=s;j<=e;j++)
        {
            if(inorder[j]==root->val)
            {
                k=j;
                break;
            }
        }
        root->right=utility(k+1,e,inorder,postorder,i);
        root->left=utility(s,k-1,inorder,postorder,i);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int s=0,e=n-1;
        int i=n-1;
       return utility(s,e,inorder,postorder,i);
        
    }
};