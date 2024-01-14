class Solution {
public:
    int parent[1005];
    int rank[1005];
    int findPar(int node){
        if(parent[node]==node)return node;
        
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
        else if(rank[u]==rank[v]){
            parent[u]=v;
            rank[v]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        unordered_map<string,int>indexMap;
        
        for(int i=0;i<n;i++){
            auto account=accounts[i];
            for(int j=1;j<accounts[i].size();j++){
                auto email=account[j];
                if(indexMap.find(email)!=indexMap.end()){
                    Union(i,indexMap[email]);
                }
               else indexMap[email]=i;
                
            }
        }
        
        unordered_map<int,set<string>>temp;
        
        for(auto i:indexMap){
            auto parent=findPar(i.second);
            temp[parent].insert(i.first);
        }
        
        vector<vector<string>>res;
        
        for(auto indx:temp){
            vector<string>curr_ans;
            curr_ans.push_back(accounts[indx.first][0]);
            for(auto email:indx.second)curr_ans.push_back(email);
            res.push_back(curr_ans);
            curr_ans.clear();
        }
        
        return res;
        
        
        
    }
};