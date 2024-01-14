/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
   
    unordered_map<Node*,Node*>visited;
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        queue<Node*>q;
        Node*  newNode=new Node(node->val);
        visited[node]=newNode;
        q.push(node);
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            for(auto nbr:x->neighbors)
            {
              Node* n=new Node(nbr->val);
                if(visited.find(nbr)==visited.end())
                {
                    visited[nbr]=n;
                    q.push(nbr);
                }
                visited[x]->neighbors.push_back(visited[nbr]);
            }
        }
        return newNode;
        
        
    }
};