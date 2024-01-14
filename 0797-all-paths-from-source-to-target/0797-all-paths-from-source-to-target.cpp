class Solution {
public:
    vector<vector<int>> res;
    
     void dfs(unordered_map<int,vector<int>> &h,int n,vector<int> &path,int source,int dest){
         path.push_back(source);
         
        if(source==dest)res.push_back(path);
         
         for(auto nbr:h[source]){
             
             dfs(h,n,path,nbr,dest);
         }
         
         path.pop_back();
         
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size();
        
        unordered_map<int,vector<int>> h;
        for(int i=0;i<graph.size();i++){
            
            for(int j=0;j<graph[i].size();j++){
                
                h[i].push_back(graph[i][j]);
            }
        }
        
        vector<int> path;
        int source=0, dest=(n-1);
        
        dfs(h,n,path,source,dest);
        return res;
    }
};