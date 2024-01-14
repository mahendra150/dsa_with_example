class Solution {
public:
    int LCS(string &str1,string &str2,vector<vector<int>> &dp,int n,int m){
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string str1=s;
        string str2=str1;
        reverse(str2.begin(),str2.end());
        
        // LPS(str1)== LCS(str1,str2)
        
        int n=str1.length();
        int m=n;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        int res=LCS(str1,str2,dp,n,m);
        
        return res;
    }
};