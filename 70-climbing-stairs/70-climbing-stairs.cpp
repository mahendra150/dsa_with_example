class Solution {
public:
    int climbStairs(int n) {
        long long  dp[50]={0};
        int k=2;
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=2*(dp[i-1])-(i-1-k>=0?dp[i-1-k]:0);
        }
        return dp[n];
    }
};