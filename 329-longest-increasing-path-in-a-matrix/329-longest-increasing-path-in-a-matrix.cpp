class Solution {
public:
    int dfs(int i,int j,int n,int m,int prev,int dp[][205],vector<vector<int>>& matrix)
    {
        //base case
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<=prev)return 0;
        //recursive case
        
        if(dp[i][j]!=(-1))return dp[i][j];
        
        
        int top=dfs(i-1,j,n,m,matrix[i][j],dp,matrix);
        int down=dfs(i+1,j,n,m,matrix[i][j],dp,matrix);
        int right=dfs(i,j+1,n,m,matrix[i][j],dp,matrix);
        int left=dfs(i,j-1,n,m,matrix[i][j],dp,matrix);
        
        return dp[i][j]= max({top,down,right,left})+1;
        
        
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int dp[205][205];
        memset(dp,(-1),sizeof(dp));
        
        int n=matrix.size();
        int m=matrix[0].size();
        int maxVal=0;
        int prev=(-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxVal=max(maxVal,dfs(i,j,n,m,prev,dp,matrix));
            }
        }
        return maxVal;
        
    }
};