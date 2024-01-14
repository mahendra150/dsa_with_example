typedef pair<int,int> node;
class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,queue<node> &q,int i,int j,int n){
        //base case
        if(i<0 or j<0 or i>=n or j>=n or visited[i][j] or !grid[i][j])return;
        
        //recursive case
        visited[i][j]= true;
        q.push({i,j});
        
        dfs(grid,visited,q,i+1,j,n);
         dfs(grid,visited,q,i-1,j,n);
         dfs(grid,visited,q,i,j-1,n);
         dfs(grid,visited,q,i,j+1,n);
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n= grid.size();
        
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<node> q;
        
        //Finding the 1st Island
        bool flag= false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    
                    dfs(grid,visited,q,i,j,n);
                    flag= true;
                    break;
                }
            }
           if(flag)break;
        }
        
        int dx[4]= {1,-1,0,0};
        int dy[4]= {0,0,1,-1};
        
        //Expanding to find the 2nd Island
        
        int steps= 0;
        while(!q.empty()){
            int size= q.size();
            
            while(size--){
                
                auto val= q.front();
            q.pop();
            
            auto curx= val.first;
            auto cury= val.second;
            
            for(int k=0;k<4;k++){
                
                auto x= curx+ dx[k];
                auto y= cury+ dy[k];
                
                if(x>=0 and x<n and y>=0 and y<n and !visited[x][y]){
                    
                    //If we find the 2nd Island
                if(grid[x][y]==1)return steps;
                
                visited[x][y]= true;
                q.push({x,y});
                    
                }
                
                
            }
                
        }
            steps+=1;
    }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<visited[i][j]<<" ";
            }cout<<endl;
        }
        return (-1);
        
    }
};