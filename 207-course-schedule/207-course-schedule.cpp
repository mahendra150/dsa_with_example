class Solution {
public:
    void makeGraph(vector<vector<int>>& prerequisites,unordered_map<int,vector<int>>&h){
        for(auto i:prerequisites){
            h[i[0]].push_back(i[1]);
        }
    }
    bool isCycle(unordered_map<int,vector<int>>&h,int node,vector<int>&path,vector<int>&visited){
        visited[node]=1;
        path[node]=1;
        
        for(auto nbr:h[node]){
            if(!visited[nbr]){
                if(isCycle(h,nbr,path,visited))return true;
            }
            else if(path[nbr])return true;
        }
        path[node]=0;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>visited(numCourses,0);
        vector<int>path(numCourses,0);
        unordered_map<int,vector<int>>h;
        makeGraph(prerequisites,h);
        
        int n=numCourses;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCycle(h,i,path,visited))return false;
            }
        }
        return true;
    }
};