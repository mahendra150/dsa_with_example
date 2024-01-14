class Solution {
public:
    class State{
    public:
    int Mask,Source;
    State(int m,int s){
        Mask=m;
        Source=s;
    }
};
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<vector<int>> dp(n,vector<int>(1<<n,1e9));
        queue<State> q;
        
        //Initial Condition
        for(int i=0;i<n;i++){
            
            dp[i][1<<i]=0;
            // auto node =new State(1<<i,i);
            State node(1<<i,i);
            q.push(node);
        }
        
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            
            auto source=node.Source;
            auto mask=node.Mask;
            
            for(auto nbr:graph[source]){
                
                auto nextMask= mask | (1<<nbr);
                if(dp[source][mask] + 1 < dp[nbr][nextMask]){
                    
                    dp[nbr][nextMask]= dp[source][mask] + 1;
                    State nextNode(nextMask,nbr);
                    q.push(nextNode);
                }
            }
            
        }
        
        auto res= INT_MAX;
        for(int i=0;i<n;i++){
            
            res=min(res,dp[i][(1<<n)-1]);
        }
        
        return res;
    }
    
};