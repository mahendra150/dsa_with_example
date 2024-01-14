class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<unsigned int>>dp(k+2,vector<unsigned int>(n,INT_MAX));
        
        for(int i=0;i<k+2;i++){
            dp[i][src]=0;
        }
        
        for(int i=1;i<=k+1;i++){
            
            for(auto node:flights){
                auto u=node[0];
                auto v=node[1];
                auto weight=node[2];
                
                if(dp[i-1][u]==INT_MAX)continue;
                dp[i][v]=min(dp[i][v],dp[i-1][u]+weight);
            }
        }
        
        return (dp[k+1][dst]==INT_MAX)?-1:dp[k+1][dst];
    }
};