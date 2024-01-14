class Solution {
public:
    bool checkNotValidBound(int i,int j,vector<vector<int>> &board,int n,int m){
        
        if(i>=0 and i<n and j>=0 and j<m)return false;
        
        return true;
    }
    int countSurroundingWater(int i,int j,vector<vector<int>> &board,int n,int m){
        
        int x1=i-1,y1=j;
        int x2=i+1,y2=j;
        int x3=i,y3=j-1;
        int x4=i,y4=j+1;
        
        int waterCount=0;
        
        if(checkNotValidBound(x1,y1,board,n,m) or board[x1][y1]==0)waterCount++;
        if(checkNotValidBound(x2,y2,board,n,m) or board[x2][y2]==0)waterCount++;
        if(checkNotValidBound(x3,y3,board,n,m) or board[x3][y3]==0)waterCount++;
        if(checkNotValidBound(x4,y4,board,n,m) or board[x4][y4]==0)waterCount++;
        
        return waterCount;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid,int &res){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=(1))return;
        
        grid[i][j]=2;
        
        int count=0;
        count+=countSurroundingWater(i,j,grid,n,m);
        
        res+=count;
        
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)dfs(i,j,n,m,grid,res);
            }
        }
        
        return res;
        
    }
};