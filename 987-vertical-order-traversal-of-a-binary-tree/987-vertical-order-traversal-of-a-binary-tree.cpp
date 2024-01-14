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
    static bool comp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second<p2.second;
        }
        return p1.first<p2.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,vector<pair<int,int>>>h;
        vector<vector<int>>ans;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
            auto x=q.front();
            q.pop();
            auto node=x.first;
            int vertical=x.second.first;
            int level=x.second.second;
            if(node)
            {
               h[vertical].push_back({level,node->val});
                if(node->left)
                {
                    q.push({node->left,{vertical-1,level+1}});
                }
                if(node->right)
                {
                    q.push({node->right,{vertical+1,level+1}});
                }
            }
            }
        }
        for(auto i:h)
        {
            vector<int>curr_ans;
            sort(i.second.begin(),i.second.end(),comp);
            for(auto p:i.second)
            {
                curr_ans.push_back(p.second);
            }
            ans.push_back(curr_ans);
            curr_ans.clear();
        }
        return ans;
        
        
        
    }
};