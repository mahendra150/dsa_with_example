class Solution {
public:
    int tin[100005];
    int low[100005];
    void makeGraph(vector<vector<int>>&connections,int n,unordered_map<int,vector<int>>&h){
        
        for(auto i:connections){
            h[i[0]].push_back(i[1]);
            h[i[1]].push_back(i[0]);
        }
    }
     void dfs(int node,int parent,unordered_map<int,vector<int>>&h,unordered_map<int,bool>&visited,vector<vector<int>>&ans,int &time){
        visited[node]=true;
         time++;
         tin[node]=low[node]=time;
         
         for(auto nbr:h[node]){
             if(parent==nbr)continue;
             
             if(!visited[nbr]){
                 dfs(nbr,node,h,visited,ans,time);
                 low[node]=min(low[node],low[nbr]);
                 if(low[nbr]>tin[node]){
                     vector<int>curr_ans;
                     curr_ans.push_back(node);
                     curr_ans.push_back(nbr);
                     ans.push_back(curr_ans);
                     curr_ans.clear();
                 }
             }
             else{
                 low[node]=min(low[node],tin[nbr]);
             }
         }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int,vector<int>>h;
        makeGraph(connections,n,h);
        vector<vector<int>>ans;
        
       for(int i=0;i<n;i++){
           tin[i]=0;
           low[i]=i;
       }
        
        unordered_map<int,bool>visited;
        int time=0;
        
        for(int i=0;i<n;i++){
            if(!visited[i])dfs(i,-1,h,visited,ans,time);
        }
        
        return ans;
        
        
    }
};