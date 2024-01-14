class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        if(n<m)return 0;
        if(m==0)return 1;
        
        vector<vector<unsigned int>>dp(n+1,vector<unsigned int>(m+1,0));
        
        for(int k=0;k<=n;k++)dp[k][0]=1;

        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
              dp[i][j]=(s[i-1]==t[j-1])*dp[i-1][j-1] + dp[i-1][j];
            }
        }
        
        return dp[n][m];
        
    }
};