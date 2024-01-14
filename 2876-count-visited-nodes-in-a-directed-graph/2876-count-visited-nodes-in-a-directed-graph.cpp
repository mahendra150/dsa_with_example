class Solution {
public:
    unordered_map<int,int> dp;
    
    int dfs(int node,int &loopEnd,unordered_map<int,vector<int>> &h){
        
    
        if(dp.find(node) != dp.end()){
            
            loopEnd= node;     // We detected a cycle
            return dp[node];
        }
        
        dp[node]=0;
        
        int count=1;
        for(auto nbr:h[node]){
            
            count+= dfs(nbr,loopEnd,h);
        }
        
        // All nodes in the cycle will have the same count;
        if(node==loopEnd){
            
            auto curr= node;
            do{
                
                dp[curr]= count;
                curr= h[curr].back();
            }while(curr != loopEnd);
        }
        
        return dp[node]= count;
    }
    void makeGraph(unordered_map<int,vector<int>> &h,vector<int> &edges,int n){
        
        for(int i=0;i<n;i++){
            
            h[i].push_back(edges[i]);
        }
        
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n= edges.size();
        
        unordered_map<int,vector<int>> h;
        makeGraph(h,edges,n);
        
        vector<int> res;
        for(int i=0;i<n;i++){
            
//             if(dp.count(i)){
                
//                 res.push_back(dp[i]);
//                 continue;
//             }
            
            int loopEnd= (-1);
            int subRes= dfs(i,loopEnd,h);
            res.push_back(subRes);
        }
        
        return res;
        
    }
};