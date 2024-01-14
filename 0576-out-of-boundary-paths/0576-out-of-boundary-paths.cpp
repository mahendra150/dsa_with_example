class Solution {
public:
    int dp[51][51][51];
    long long mod=1000000007;
    
    int dfs(int m,int n,int i,int j,int maxMove){
        //base case
        if(i<0 or i>=m or j<0 or j>=n)return 1;
        //recursive case
        if(maxMove<=0)return 0;
        
        if(dp[i][j][maxMove] != (-1))return dp[i][j][maxMove];
        
        int top=dfs(m,n,i-1,j,maxMove-1);
        int bottom=dfs(m,n,i+1,j,maxMove-1);
        int left=dfs(m,n,i,j-1,maxMove-1);
        int right=dfs(m,n,i,j+1,maxMove-1);
        
        return dp[i][j][maxMove]=( top%mod + bottom%mod + left%mod + right%mod )%mod;
        
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,(-1),sizeof(dp));
        
        return dfs(m,n,startRow,startColumn,maxMove);
    }
};