class Solution {
public:
    bool isMatch(string s, string p) {
       int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m and p[j-1]=='*';j++)
        {
            if(dp[0][j-1]) dp[0][j]=true; 
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //diagonal check
                if(s[i-1]==p[j-1] or p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    //'*' Rule
                    //once we exclude   or  once we include a sequence
                    dp[i][j]=dp[i][j-1] or dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};