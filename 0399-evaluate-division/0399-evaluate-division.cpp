class Solution {
public:
    void dfs(string source,string destination,unordered_map<string,vector<pair<string,double>>> &h,set<string> &visited,double &ans,double temp){
        
        if(source==destination)ans=temp;
        
        visited.insert(source);
        
        for(auto nbr:h[source]){
            
            auto nbrNode=nbr.first;
            // auto edgeWeight= nbr.second;
            if(visited.find(nbrNode)==visited.end()){
                dfs(nbrNode,destination,h,visited,ans,temp*nbr.second);
            }
        }
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n= equations.size();
        
        unordered_map<string,vector<pair<string,double>>> h;
        for(int i=0;i<n;i++){
            
            h[equations[i][0]].push_back({equations[i][1],values[i]});
            h[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        
        vector<double> res;
        for(int i=0;i<queries.size();i++){
            
            auto source= queries[i][0];
            auto destination= queries[i][1];
            set<string> visited;
            double ans=(-1);
            if(h.count(source))dfs(source,destination,h,visited,ans,1);
            res.push_back(ans);
        }
        
        return res;
        
        
    }
};