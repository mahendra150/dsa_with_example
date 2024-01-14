class Solution {
public:
    void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,vector<int>> &h){
        
        visited[node]=true;
        for(auto nbr: h[node]){
            if(!visited[nbr]){
                dfs(nbr,visited,h);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return (-1);
        
        unordered_map<int,vector<int>> h;
        unordered_map<int,bool> visited;
        
        for(auto node: connections){
            
            h[node[0]].push_back(node[1]);
            h[node[1]].push_back(node[0]);
        }
        
        
        for(int i=0;i<n;i++){
            visited[i]= false;
        }
        
        int connectedComponents=0;
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
                connectedComponents+=1;
                dfs(i,visited,h);
            }
        }
        
        int numberOfOperations= connectedComponents-1;
        
        return numberOfOperations;
        
    }
};