class Solution {
public:
    unordered_map<int,int> dp;
    int res;
    
    int dfs(int node,unordered_map<int,vector<int>> &h,int &loopEnd){
        
        if(dp.find(node) != dp.end()){
            
            loopEnd= node;
            return dp[node];
        }
        
        dp[node]=0;
        
        int count=1;
        for(auto nbr:h[node]){
            
            count+= dfs(nbr,h,loopEnd);
        }
        
        
        if(node==loopEnd){
            
            auto curr= node;
            res=max(res,count);
            do{
                
                dp[curr]= count;
                curr= h[curr].back();
                
            }while(curr != loopEnd);
        }
        
        
        return dp[node]= count;
    }
    void makeGraph(vector<int> &edges,unordered_map<int,vector<int>> &h,int n){
        
        for(int i=0;i<n;i++){
            
            if(edges[i] != (-1))h[i].push_back(edges[i]);
        }
        
    }
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        
        unordered_map<int,vector<int>> h;
        makeGraph(edges,h,n);
        
        res=0;
        for(int i=0;i<n;i++){
            
            int loopEnd= (-1);
            dfs(i,h,loopEnd);
        }
        
        return res==0?(-1):res;
        
    }
};