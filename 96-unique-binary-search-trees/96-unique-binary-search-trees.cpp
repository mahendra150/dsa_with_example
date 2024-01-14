class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
        
    }
};