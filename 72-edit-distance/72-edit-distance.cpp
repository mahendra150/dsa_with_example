class Solution {
public:
    int utility(int n,int m,string word1,string word2,int dp[][505])
    {
        //base case
        if(n==0)return m;
        if(m==0)return n;
        if(dp[n][m]!=(-1))
        {
            return dp[n][m];
        }
        //recursive case
        if(word1[n-1]==word2[m-1])
        {
           return dp[n][m]=utility(n-1,m-1,word1,word2,dp);
        }
            int opt1=utility(n,m-1,word1,word2,dp);
            int opt2=utility(n-1,m,word1,word2,dp);
            int opt3=utility(n-1,m-1,word1,word2,dp);
            return dp[n][m]=min({opt1,opt2,opt3})+1;
        
    }
    int minDistance(string word1, string word2) {
       int n=word1.length();
        int m=word2.length();
        int dp[505][505];
        memset(dp,-1,sizeof(dp));
       return utility(n,m,word1,word2,dp);
        
        
    }
};