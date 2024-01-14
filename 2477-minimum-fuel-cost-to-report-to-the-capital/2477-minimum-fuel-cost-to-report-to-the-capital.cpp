class Solution {
public:
    long long int fuel;
    void makeGraph(vector<vector<int>> &roads,unordered_map<int,vector<int>> &h){
        int n=roads.size();
        
        for(int i=0;i<n;i++){
            
            h[roads[i][0]].push_back(roads[i][1]);
            h[roads[i][1]].push_back(roads[i][0]);
        }
        
    }
    long long int dfs(int node,int seats,unordered_map<int,vector<int>> &h,unordered_map<int,bool> &visited){
        
        long long int nodeCount=0;
        visited[node]= true;
        
        for(auto nbr:h[node]){
            
            if(!visited[nbr])nodeCount+= dfs(nbr,seats,h,visited);
        }
        
        nodeCount+=1;
        
        // if(nodeCount%seats==0){
        //     fuel+= (nodeCount/seats);
        // }
        // fuel+= (nodeCount/seats);
        
       if(nodeCount<=seats)fuel+= 1;
        
        else {
            long long int temp= nodeCount;
            long long int rem= temp%seats;
            temp/=seats;
            fuel+= temp;
            if(rem>0)fuel+= 1;
        }
        
        return nodeCount;
        
        
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        
        unordered_map<int,vector<int>> h;
        makeGraph(roads,h);
        
        int res=0;
        unordered_map<int,bool> visited;
        visited[0]= true;
        
        fuel=0;
        for(auto nbr:h[0]){
            
            long long int nodeCount=0;
            if(!visited[nbr])
            {
                dfs(nbr,seats,h,visited);
            }

        }
        
        return fuel;
        
    }
};