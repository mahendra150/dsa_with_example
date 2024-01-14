class Solution {
public:
    vector<int> dp;
    bool dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited,int n,int m){
        
        //base case
        if(i<0 or i>=n or j<0 or j>=m or visited[i][j])return false;
        
        
        if(j+1<m and grid[i][j]==1 and grid[i][j+1]==(-1))return false;
        
        if(j-1>=0 and grid[i][j]==(-1) and grid[i][j-1]==(1))return false;
        
        if(grid[i][j]==1 and j+1>=m)return false;
        
        if(grid[i][j]==(-1) and j-1<0)return false;
        
        if(i==n-1){
            
            if(grid[i][j]==(-1) and j-1>=0){
                dp.push_back(j-1);
                return true;
            }
            else if(grid[i][j]==1 and j+1<m){
                dp.push_back(j+1);
                return true;
            }
            
            return false;
        }
        
        //recursive case
        
        visited[i][j]= true;
        
        bool option1= false;
        bool option2= false;
        if(grid[i][j]==1){
            
            option1= dfs(i+1,j+1,grid,visited,n,m);
        }
        else if(grid[i][j]==(-1)){
            
            option2= dfs(i+1,j-1,grid,visited,n,m);
        }
        
        return option1 or option2;
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        for(int j=0;j<m;j++){
            
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            auto check= dfs(0,j,grid,visited,n,m);
            if(!check)dp.push_back({-1});
        }
        
        return dp;
    }
};