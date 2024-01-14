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
    int maxFreq;
    unordered_set<int> st;
    vector<int> res;
    
    void dfs(TreeNode* root,TreeNode* &prev,int &prevFreq){
        
        //base case
        if(!root)return;
        
        //recursive case
        
        dfs(root->left,prev,prevFreq);
        
        if(prev){
            
            if(root->val==prev->val){
                
                prevFreq+=1;
            }
            else prevFreq=1;
        }
        
        if(prevFreq>maxFreq){
            
            st.clear();
            st.insert(root->val);
            maxFreq= prevFreq;
        }
        else if(prevFreq==maxFreq and !st.count(root->val))st.insert(root->val);
        
        prev=root;
        
        dfs(root->right,prev,prevFreq);
    }
    vector<int> findMode(TreeNode* root) {
        
        TreeNode* prev= NULL;
        int prevFreq=1;
        maxFreq= 0;
        dfs(root,prev,prevFreq);
        
        while(!st.empty()){
            
            auto val= *st.begin();
            st.erase(*st.begin());
            
            res.push_back(val);
        }
        
        return res;
    }
};