class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &matrix,int n,int m){
        //base case
        if(i<0 or j<0 or i>=n or j>=m)return 1e9;
        if(i==n-1 and j==m-1){
            return (matrix[i][j]<=0)?(1-matrix[i][j]):1;
        }
        
        //recursive case
        if(dp[i][j] != (-1))return dp[i][j];
        
        int ans=INT_MAX;
        
        int right=dfs(i,j+1,matrix,n,m);
        int down=dfs(i+1,j,matrix,n,m);
        
        ans= min(right,down) - matrix[i][j];
        
        return dp[i][j]= (ans<=0)?1:ans;
    }
    vector<vector<int>> dp;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        
        dp.resize(205,vector<int>(205,-1));
        
        int i=0,j=0;
        return dfs(i,j,dungeon,n,m);
        
    }
};