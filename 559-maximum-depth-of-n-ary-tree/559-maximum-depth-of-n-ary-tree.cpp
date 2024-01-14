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
    int maxDepth(Node* root) {
        if(!root)return 0;
        queue<Node*>q;
        
        int level=0;
        
        q.push(root);
        
        while(!q.empty()){
            level++;
            int n=q.size();
            while(n--){
                auto curr=q.front();
                q.pop();
                for(auto nbr:curr->children){
                    q.push(nbr);
                }
            }
        }
        
        return level;
        
    }
};