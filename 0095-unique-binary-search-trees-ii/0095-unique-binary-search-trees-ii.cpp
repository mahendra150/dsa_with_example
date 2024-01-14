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
    vector<TreeNode*> dfs(int start,int end){
        
        //base case
        vector<TreeNode*> ans;
        
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        
        //recursive case
        
        for(int mid=start;mid<=end;mid++){
            
            vector<TreeNode*> left= dfs(start,mid-1);
            vector<TreeNode*> right= dfs(mid+1,end);
            
            for(int i=0;i<left.size();i++){
                for(int j=0;j<right.size();j++){
                    
                  TreeNode* newNode = new TreeNode(mid,left[i],right[j]);
                    ans.push_back(newNode);
                }
            }
        }
        
            return ans;
    }
        
    vector<TreeNode*> generateTrees(int n) {
        
       vector<TreeNode*> res= dfs(1,n);
        
        return res;
        
    }
};