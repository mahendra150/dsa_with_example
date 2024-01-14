class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        int dp[1000][1000];
        memset(dp,sizeof(dp),0);
       
        /*
        for(int k=0;k<=n;k++)
        {
            dp[0][k]=0;
        }
        
        for(int k=0;k<=m;k++)
        {
            dp[k][0]=0;
        }
        */
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[j-1]==text2[i-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
        
    }
};