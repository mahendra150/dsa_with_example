class Solution {
public:
    void topoSort(unordered_map<int,vector<int>>&h,stack<int>&s,vector<int>&visited,int node){
        visited[node]=1;
        
        for(auto nbr:h[node]){
            if(!visited[nbr])topoSort(h,s,visited,nbr);
        }
        s.push(node);
    }
    void makeGraph(unordered_map<int,vector<int>>&h,vector<vector<int>>& prerequisites){
        for(auto x:prerequisites){
            h[x[0]].push_back(x[1]);
        }
    }
    bool isCycle(unordered_map<int,vector<int>>&h,vector<int>&visited,int node,vector<int>&path){
        
        visited[node]=1;
        path[node]=1;
        
        for(auto nbr:h[node]){
            if(!visited[nbr]){
                if(isCycle(h,visited,nbr,path))return true;
            }
            else if(path[nbr])return true;
            
        }
        
        path[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>h;
        
        makeGraph(h,prerequisites);
        
        int n=numCourses;
        vector<int>visited(n,0);
        vector<int>path(n,0);
        bool check=false;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCycle(h,visited,i,path))check=true;
            }
        }
        
        if(check)return {};
        
        for(int i=0;i<n;i++)visited[i]=0;
        stack<int>s;
        
        for(int i=0;i<n;i++){
            if(!visited[i])topoSort(h,s,visited,i);
        }
        
        vector<int>ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};