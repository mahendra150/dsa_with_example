/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        queue<Node*> q;
        
        vector<vector<int>> res;
        q.push(root);
        
        while(!q.empty()){
            
            int n=q.size();
            vector<int>subRes;
            while(n--){
                
               auto node= q.front();
                q.pop();
                subRes.push_back(node->val);
                
                for(auto nbr:node->children){
                    
                    q.push(nbr);
                }
            }
            res.push_back(subRes);
            subRes.clear();
        }
        
        return res;
        
    }
};