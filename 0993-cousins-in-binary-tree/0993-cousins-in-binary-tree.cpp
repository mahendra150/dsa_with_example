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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level1=INT_MIN,level2=INT_MIN;
        
        int steps=0;
        while(!q.empty()){
            
            int n= q.size();
            while(n--){
                
                auto node= q.front();
                q.pop();
                
                if(node->left and node->right){
                    
                    auto left= node->left->val;
                    auto right= node->right->val;
                    if(left==x and right==y)return false;
                    if(left==y and right==x)return false;
                }
                if(node->val==x)level1= steps;
                if(node->val==y)level2= steps;
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            
            steps+=1;
        }
        
        return level1==level2;
    }
};