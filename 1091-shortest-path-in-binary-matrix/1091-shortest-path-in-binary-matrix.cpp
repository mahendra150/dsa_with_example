typedef pair<int,int> node;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        
        if(grid[0][0]==1 or grid[n-1][n-1]==1)return (-1);
        
        queue<node> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        q.push({0,0});
        visited[0][0]= true;
        
        int dx[8]={1,-1,0,0,-1,1,-1,1};
        int dy[8]={0,0,1,-1,-1,-1,1,1};
        int steps=0;
        while(!q.empty()){
            
            int size= q.size();
            while(size--){
                
                auto val= q.front();
                q.pop();
                auto curx= val.first;
                auto cury= val.second;
                
                if(curx==n-1 and cury==n-1)return steps+1;
                
                for(int k=0;k<8;k++){
                    
                    auto x= curx + dx[k];
                    auto y= cury + dy[k];
                    
                    if(x>=0 and x<n and y>=0 and y<n and !visited[x][y] and grid[x][y]==0){
                        
                        visited[x][y]= true;
                        q.push({x,y});
                    }
                }
            }
            
            steps+=1;
        }
        
        return (-1);
    }
};