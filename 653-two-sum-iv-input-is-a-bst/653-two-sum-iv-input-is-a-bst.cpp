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
class bstIterator{
    public:
    bool reverse=true;
    stack<TreeNode*>s;
    void pushAll(TreeNode* root)
    {
        TreeNode* temp=root;
        while(temp)
        {
            s.push(temp);
        if(!reverse)
        {
           temp=temp->left; 
        }
            else
            {
                temp=temp->right;
            }
            
        }
    }
    int next()
    {
        auto node=s.top();
        s.pop();
        if(reverse)
        {
            if(node->left)
            {
                pushAll(node->left);
            }
        }
        else
        {
            if(node->right)
            {
                pushAll(node->right);
            }
        }
        return node->val;
    }
   bstIterator(TreeNode* root,bool isReverse)
    {
        reverse=isReverse;
        pushAll(root);
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bstIterator l(root,false);
        bstIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)return true;
            else if(i+j<k)i=l.next();
            else j=r.next();
        }
        return false;
        
    }
};