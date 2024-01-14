class Solution {
public:
    int parent[20005];
    int rank[20005];
    
    int findPar(int node){
        if(parent[node]==node)return node;
        
        return parent[node]=findPar(parent[node]);
    }
    
    void Union(int u,int v){
        u=findPar(u);
        v=findPar(v);
        
        if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[u]==rank[v]){
            parent[v]=u;
            rank[u]++;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        int totalNodes=20005;
        for(int i=0;i<totalNodes;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        int totalNumberOfStones=n;
        int leftoverStones;
        int numberOfStonesRemoved;
        
        for(auto val:stones){
            auto i=val[0];
            auto j=val[1];
            
            Union(i,j+10001);
        }
        
        set<int>components;
        
        for(auto val:stones){
            auto i=val[0];
            auto p=findPar(i);
            components.insert(p);
        }
        
        //leftoverStones=numberOfConnectedComponents
        
        leftoverStones=components.size();
        
        numberOfStonesRemoved=totalNumberOfStones-leftoverStones;
        
        
        return numberOfStonesRemoved;
        
        
        
        
    }
};