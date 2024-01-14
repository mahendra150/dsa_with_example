class Solution {
public:
    int mod=1e9+7;
    int numTilings(int n) {
        vector<unsigned int>dp(1005,0);
        
        //Base Cases
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        
        for(int i=4;i<=n;i++){
            dp[i]= 2*(dp[i-1]) + dp[i-3];
            dp[i]=dp[i]%mod;
        }
        
        return dp[n];
    }
};