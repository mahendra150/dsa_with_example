class Solution {
public:
    int utility(string word1,string word2,int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        
        int LCS=utility(word1,word2,n,m);
        
        int maxNumberOfDeletions=(n+m);
        
        int res=maxNumberOfDeletions-2*(LCS);
        
        return res;
    }
};