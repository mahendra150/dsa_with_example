class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid,int n,int m){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=1)return 0;
        
        grid[i][j]=2;
        
        
        int left=dfs(i,j-1,grid,n,m);
        int right=dfs(i,j+1,grid,n,m);
        int top=dfs(i-1,j,grid,n,m);
        int bottom=dfs(i+1,j,grid,n,m);
        
        return left+right+top+bottom+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(i,j,grid,n,m));
                }
            }
        }
        
        return ans;
        
    }
};