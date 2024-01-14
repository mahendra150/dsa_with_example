class Solution {
public:
    vector<vector<int>> dp;
    
    int LCS(string str1,string str2){
        int n= str1.length();
        int m= str2.length();
        
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
    int minInsertions(string s) {
        int n= s.length();
        dp.resize(505,vector<int>(505,0));
        
        string str1= s;
        string str2= s;
        reverse(str2.begin(),str2.end());
        
        int LPS= LCS(str1,str2);
        
        int minimumInsertions= n-LPS;
        
        return minimumInsertions;
        
    }
};