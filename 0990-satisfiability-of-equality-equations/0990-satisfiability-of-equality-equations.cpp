class Solution {
public:
        vector<int>parent;
        vector<int> rank;
    int findPar(int node){
        if(node==parent[node])return node;
        
        return parent[node]=findPar(parent[node]);
    }
    
    void Union(int u,int v){
         u= findPar(u);
          v=findPar(v);  
        
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
        
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        for(auto node:equations){
            auto sign=node[1];
            auto u=node[0]-97;
            auto v=node[3]-97;
            if(sign=='='){
                 if(findPar(u) != findPar(v))
                Union(u,v);
            }
        }
        
        for(auto node:equations){
            auto sign=node[1];
            auto u=node[0]-97;
            auto v=node[3]-97;
            if(sign=='!'){
                if( findPar(u)==findPar(v) )return false;
            }
        }
        
        return true;
    }
};