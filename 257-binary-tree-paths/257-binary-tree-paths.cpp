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
    void Path(TreeNode* root,string curr_ans,vector<string>&result)
    {
        //base case
        if(!root)
        {
            return;
        }
        //recursive case
        curr_ans=curr_ans + "->"+ to_string(root->val);
        if(!root->left and !root->right)
        {
            string temp=curr_ans.substr(2);
            result.push_back(temp);
            return;
        }
        Path(root->left,curr_ans,result);
        Path(root->right,curr_ans,result);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string curr_ans="";
        vector<string>result;
        Path( root,curr_ans,result);
        return result;
        
    }
};