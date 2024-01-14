class Solution {
public:
     // double dp[30][30][105];
    
    double dfs(int i,int j,int k,int n,vector<vector<vector<double>>> &dp){
        //base case
        if(i<0 or i>=n or j<0 or j>=n)return 0;
        //recursive case
        if(k==0)return 1.0;
        
        if(dp[i][j][k] != (-1))return dp[i][j][k];
        
        double dir1=dfs(i-2,j+1,k-1,n,dp);
        double dir2=dfs(i-2,j-1,k-1,n,dp);
        double dir3=dfs(i-1,j-2,k-1,n,dp);
        double dir4=dfs(i-1,j+2,k-1,n,dp);
        double dir5=dfs(i+2,j+1,k-1,n,dp);
        double dir6=dfs(i+2,j-1,k-1,n,dp);
        double dir7=dfs(i+1,j+2,k-1,n,dp);
        double dir8=dfs(i+1,j-2,k-1,n,dp);
        
        double probability=(dir1+dir2+dir3+dir4+dir5+dir6+dir7+dir8);
        probability=(probability)/8;
        
        return dp[i][j][k]=probability;
        
    }
    double knightProbability(int n, int k, int row, int column) {
         // memset(dp,(-1),sizeof(dp));
        
vector<vector<vector<double>>> dp(n + 1, vector<vector<double>> (n + 1, vector<double>(k + 1, -1)));

        
        return dfs(row,column,k,n,dp);
    }
};