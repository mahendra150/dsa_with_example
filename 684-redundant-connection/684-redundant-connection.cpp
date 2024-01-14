class Solution {
public:
    int parent[1005],rank[1005];
    
    int findPar(int node){
        if(node==parent[node])return node;
        
        return  parent[node]= findPar(parent[node]);
    }
    void Union(int u,int v){
        u=findPar(u);
        v=findPar(v);
        
        if(rank[v]>rank[u])parent[u]=v;
        else if(rank[u]>rank[v])parent[v]=u;
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>ans;
        
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        for(int i=0;i<n;i++){
            auto u=edges[i][0];
            auto v=edges[i][1];
            
            if(findPar(u)==findPar(v)){
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
            else{
                Union(u,v);
            }
        }
        
        return ans;
        
    }
};