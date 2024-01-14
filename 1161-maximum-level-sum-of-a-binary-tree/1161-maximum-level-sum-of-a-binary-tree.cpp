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
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int maxSum=INT_MIN;
        int level=0;
        int requiredLevel;
        
        while(!q.empty()){
            int n=q.size();
            int currSum=0;
            level++;
            while(n--){
                auto node=q.front();
                q.pop();
                currSum+=(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            
            if(currSum>maxSum){
                maxSum=currSum;
                requiredLevel=level;
            }
        }
        
        return requiredLevel;
        
    }
};