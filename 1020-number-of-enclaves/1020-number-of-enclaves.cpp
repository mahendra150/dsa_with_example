class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int n,int m,vector<vector<bool>> &visited){
        
        //base case
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0 or  visited[i][j])return;
        
        //recursive case
        visited[i][j]= true;
        
        dfs(grid,i+1,j,n,m,visited);
        dfs(grid,i-1,j,n,m,visited);
        dfs(grid,i,j-1,n,m,visited);
        dfs(grid,i,j+1,n,m,visited);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        queue<int>q;
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==1)dfs(grid,0,j,n,m,visited);
            if(grid[n-1][j]==1)dfs(grid,n-1,j,n,m,visited);
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)dfs(grid,i,0,n,m,visited);
            if(grid[i][m-1]==1)dfs(grid,i,m-1,n,m,visited);
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1 and !visited[i][j])res+=1;
            }
        }
        
        return res;
        
        
        
    }
};