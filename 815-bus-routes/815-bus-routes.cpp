class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=routes.size();
        
        unordered_map<int,vector<int>>graph;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                graph[routes[i][j]].push_back(i);
            }
        }
        
        unordered_map<int,bool>visitedRoute;
        unordered_map<int,bool>visitedStop;
        
        queue<pair<int,int>>q;
        
        visitedStop[source]=true;
        int bus=0;
        q.push({source,bus});
        
        while(!q.empty()){
            auto stop=q.front().first;
            auto bus=q.front().second;
            q.pop();
            if(stop==target)return bus;
            
            for(auto route:graph[stop]){
                if(!visitedRoute[route]){
                    for(auto i:routes[route]){
                        if(!visitedStop[i]){
                            visitedStop[i]=true;
                            q.push({i,bus+1});
                        }
                    }
                }
                visitedRoute[route]=true;
            }
        }
        
        return -1;
        
    }
};