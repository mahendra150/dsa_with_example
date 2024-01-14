class Solution {
public:
    void LCS(string str1,string str2,int n,int m,vector<vector<int>> &dp){
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        // return dp[n][m];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        LCS(str1,str2,n,m,dp);
        
        //SCS --> (n+m) - lcs;
        
        string ans="";
        int i=n,j=m;
        while(i>0 and j>0){
            if(str1[i-1]==str2[j-1]){
                //If char is present in both str1 and str2
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans.push_back(str1[i-1]);
                i--;
            }
            else{
                ans.push_back(str2[j-1]);
                j--;
            }
        }
        
        
        //For remaining characters
        
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};