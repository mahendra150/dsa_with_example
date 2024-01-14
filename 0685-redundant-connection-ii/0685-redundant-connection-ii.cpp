class Solution {
public:
    
    class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n){
        
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=1;i<=n;i++){
            parent[i]= i;
        }
    }
    
    int findPar(int node){
        
        if(parent[node]==node)return node;
        
        return parent[node]=findPar(parent[node]);
    }
    
    bool Union(int u,int v){
        
        u= findPar(u);
        v= findPar(v);
        if(u==v)return false;
        
        if(rank[u]<rank[v]){
            parent[u]= v;
        }
        else if(rank[v]<rank[u]){
            
            parent[v]= u;
        }
        else{
            
            parent[u]= v;
            rank[v]++;
        }
        
        return true;
    }
};
    
    vector<int> formGraphBySkippingNode(vector<vector<int>> &edges,int skip){
        int n= edges.size();
        
        DSU uf(n);
        
        for(int i=0;i<n;i++){
            
            if(i==skip)continue;
            else if( !uf.Union(edges[i][0],edges[i][1]) ){
                return edges[i];
            }
        }
        
        return {};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> inDegree(n+1,0);
        
        int hasTwoInDegree= (-1);
        for(auto i:edges){
            inDegree[i[1]]+=1;
            
            if(inDegree[i[1]]==2) hasTwoInDegree= i[1];
        }
        
        if(hasTwoInDegree== (-1)){
            // Violation II
            return formGraphBySkippingNode(edges,-1);
        }
        else{
            // Violation I
            for(int i=n-1;i>=0;i--){
                
                if(edges[i][1]== hasTwoInDegree){
                    
                    auto res= formGraphBySkippingNode(edges,i);
                    if(res.size()==0)return edges[i];
                }
            }
        }
        
        
        return {};
    }
};