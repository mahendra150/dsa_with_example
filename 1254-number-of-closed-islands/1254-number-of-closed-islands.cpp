class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid,int n,int m){
        //base case
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=0)return;
        
        //recursive case
        grid[i][j]=3;
        
        dfs(i+1,j,grid,n,m);
        dfs(i-1,j,grid,n,m);
        dfs(i,j+1,grid,n,m);
        dfs(i,j-1,grid,n,m);
        
    }
    void surroundedRegion(int i,int j,vector<vector<int>> &grid,int n,int m){
        //base case
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=0)return;
        
        //recursive case
        grid[i][j]=2;
        
        surroundedRegion(i+1,j,grid,n,m);
        surroundedRegion(i-1,j,grid,n,m);
        surroundedRegion(i,j+1,grid,n,m);
        surroundedRegion(i,j-1,grid,n,m);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int j=0;j<m;j++){
            
            if(grid[0][j]==0)surroundedRegion(0,j,grid,n,m);
            if(grid[n-1][j]==0)surroundedRegion(n-1,j,grid,n,m);
        }
        
        for(int i=0;i<n;i++){
            
            if(grid[i][0]==0)surroundedRegion(i,0,grid,n,m);
            if(grid[i][m-1]==0)surroundedRegion(i,m-1,grid,n,m);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==0){
                    count++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        
        return count;
        
    }
};