class Solution {
public:
    int dp[105][105];
    int utility(vector<vector<int>>& obstacleGrid,int dp[][105],int i,int j)
    {
        //base case
        if(i==0 and j==0 and obstacleGrid[i][j]!=1)return dp[i][j]=1;
        if(i<0 or j<0)return  0;
        if(obstacleGrid[i][j]==1)return dp[i][j]=0;
        if(dp[i][j]!=(-1))
        {
            return dp[i][j];
        }
        //recursive case
       return dp[i][j]= utility( obstacleGrid,dp,i,j-1) + utility( obstacleGrid,dp,i-1,j);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
       // vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=(-1);
            }
        }
        int i=n-1,j=m-1;
      return utility(obstacleGrid,dp,i,j);
       // return dp[n-1][m-1];
        
    }
};