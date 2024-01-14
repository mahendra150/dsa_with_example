class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //base case
        if(amount==0)return 1;
        if(coins.size()==0)return 0;
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
       dp[0][0]=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0 and j>0)
                {
                   dp[i][j]=0; 
                }
                 else if(j==0)
                {
                  dp[i][j]=1;  
                }
                else
                {
                dp[i][j]=dp[i-1][j]+(j-coins[i-1]>=0?dp[i][j-coins[i-1]]:0);
                }
            
            }
        }
        return dp[n][amount];
    }
};