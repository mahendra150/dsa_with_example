class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,int n,int m)
    {
        //base case
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!='1')return;
        grid[i][j]='2';
        
        //traverse in all four directions
        dfs(i-1,j,grid,n,m);
        dfs(i+1,j,grid,n,m);
        dfs(i,j-1,grid,n,m);
        dfs(i,j+1,grid,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return count;
        
    }
};