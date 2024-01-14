class Solution {
public:
    unordered_map<string,vector<string>>h;
    unordered_map<string,int>outDegree;
    vector<string>path;
    
    void dfs(string node){
        
        while(outDegree[node]){
            outDegree[node]--;
            auto next= h[node].back();
            h[node].pop_back();
            dfs(next);
        }
        
        path.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto i:tickets){
            h[i[0]].push_back(i[1]);
            outDegree[i[0]]++;
        }
        
       for(auto &node:h){
           sort(node.second.begin(),node.second.end(),greater<string>());
       }
        
        
        auto start="JFK";
        dfs(start);
        
        reverse(path.begin(),path.end());
        
        
        return path;
        
    }
};