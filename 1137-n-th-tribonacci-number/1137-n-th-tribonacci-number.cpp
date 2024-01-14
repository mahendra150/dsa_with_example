class Solution {
public:
    int tribonacci(int n) {
        long long  dp[45];
        dp[0]=0;
            dp[1]=dp[2]=1;
       int k=3;
        for(int i=3;i<=n;i++)
        {
            dp[i]=2*dp[i-1]-(i-1-k>=0?dp[i-1-k]:0);
        }
        return dp[n];
        
        
    }
};