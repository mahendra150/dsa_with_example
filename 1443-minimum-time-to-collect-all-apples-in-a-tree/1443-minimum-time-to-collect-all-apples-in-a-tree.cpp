class Solution {
public:
    unordered_map<int,vector<int>> h;
    int res;
    
    void makeGraph(vector<vector<int>> &edges){
        int n= edges.size();
        
        for(int i=0;i<n;i++){
            
            h[edges[i][0]].push_back(edges[i][1]);
            h[edges[i][1]].push_back(edges[i][0]);
        }
        
    }
    
    int dfs(int node,vector<bool> &hasApples,unordered_map<int,bool> &visited,int parent){
        
        visited[node]= true;
        
        int steps= 0;
        for(auto nbr:h[node]){
            
            if(!visited[nbr]){
                
                steps+= dfs(nbr,hasApples,visited,node);
            }
        }
        
        if(hasApples[node] and node != 0){
            
            steps+=2;
            hasApples[parent]= true;
        }
        
        return steps;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        makeGraph(edges);
        
        unordered_map<int,bool> visited;
        
        res= dfs(0,hasApple,visited,0);
        
        return res;
    }
};