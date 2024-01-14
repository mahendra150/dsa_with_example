/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        //base case
        if(!root)return;
        //recursive case
        if(root->left)
        {
            parent[root->left]=root;
            findParent(root->left,parent);
        }
        if(root->right)
        {
            parent[root->right]=root;
            findParent(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!k)
        {
            return {target->val};
        }
        unordered_map<TreeNode*,TreeNode*>parent;
        findParent(root,parent);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        while(!q.empty())
        {
            k--;
            int n=q.size();
            while(n--)
            {
                auto x=q.front();
                q.pop();
                if(x->left and !visited[x->left])
                {
                    visited[x->left]=true;
                    q.push(x->left);
                }
                if(x->right and !visited[x->right])
                {
                    visited[x->right]=true;
                    q.push(x->right);
                }
                if(parent.count(x)>0 and !visited[parent[x]])
                {
                    visited[parent[x]]=true;
                    q.push(parent[x]);
                }
            }
            if(k==0)
            {
                break;
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};