typedef pair<int,pair<int,int>>node;
class Solution {
public:
    int parent[1005];
    int rank[1005];
    int findPar(int node){
        if(node==parent[node])return node;
        
        return parent[node]=findPar(parent[node]);
    }
    void Union(int u,int v){
        u=findPar(u);
        v=findPar(v);
        
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        priority_queue<node,vector<node>,greater<node>>q;
        
        for(int i=0;i<n;i++){
            auto p1=points[i];
            for(int j=i+1;j<n;j++){
                auto p2=points[j];
                auto dist= abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                q.push({dist,{i,j}});
            }
        }
        
        int cost=0;
        while(!q.empty()){
            auto val=q.top();
            q.pop();
            auto u=val.second.first;
            auto v=val.second.second;
            if(findPar(u)!=findPar(v)){
                cost+=val.first;
                Union(u,v);
            }
        }
        
        return cost;
        
        
    }
};