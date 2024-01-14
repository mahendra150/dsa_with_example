class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &h,unordered_map<int,bool> &visited){
        
        visited[node]= true;
        
        for(auto nbr:h[node]){
            
            if(!visited[nbr]){
                
                dfs(nbr,h,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        
        unordered_map<int,vector<int>> h;
        
        for(int i=0;i<isConnected.size();i++){
            
            for(int j=0;j<isConnected[i].size();j++){
                
                if(isConnected[i][j]==1){
                    
                    h[i].push_back(j);
                    h[j].push_back(i);
                }
            }
        }
        
        unordered_map<int,bool> visited;
        int count=0;
        
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
                
                count+=1;
                dfs(i,h,visited);
            }
        }
        
        return count;
        
    }
};