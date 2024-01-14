class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_map<int,vector<int>> h;
        for(auto node:dislikes){
            h[node[0]].push_back(node[1]);
            h[node[1]].push_back(node[0]);
        }
        
        queue<int> q;
        vector<int> color(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(!color[i]){
                color[i]=1;
                q.push(i);
                while(!q.empty()){
                    auto node= q.front();
                    q.pop();
                    
                    for(auto nbr:h[node]){
                        if(!color[nbr]){
                            color[nbr]=(-color[node]);
                            q.push(nbr);
                        }
                        else if(color[nbr]==color[node])return false;
                    }
                }
            }
        }
        
        return true;
        
    }
};