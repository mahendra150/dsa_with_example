class Solution {
public:
    bool isOutOfBounds(int i,int j,int n,int m){
        
        if(i==0 or j==0 or i==n-1 or j==m-1)return true;
        
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n= maze.size();
        int m= maze[0].size(); 
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int dx[4]= {1,-1,0,0};
        int dy[4]= {0,0,1,-1};
        int row=entrance[0],col=entrance[1];
        
        int steps=0;
        visited[row][col]= true;
        if(row==0 or col==0 or row==n-1 or col==m-1){
            
            for(int k=0;k<4;k++){
                
                auto x= row + dx[k];
                auto y= col + dy[k];
                if(x>=0 and x<n and y>=0 and y<m and !visited[x][y] and maze[x][y] != '+'){
                    
                    visited[x][y]= true;
                    q.push({x,y});
                }
            }
            steps+=1;
        }
        else {
            q.push({row,col});
            visited[row][col]= true;
        }
        
        
        while(!q.empty()){
            
            int size=q.size();
            while(size--){
                
                auto val= q.front();
                q.pop();
                auto curx=val.first;
                auto cury=val.second;
                cout<<curx<<" "<<cury<<endl;
        if (maze[curx][cury]=='.' and isOutOfBounds(curx,cury,n,m))return steps;
                
                for(int k=0;k<4;k++){
                    
                    auto x= curx + dx[k];
                    auto y= cury + dy[k];
                    if(x>=0 and x<n and y>=0 and y<m and !visited[x][y] and maze[x][y] == '.'){
                        // if(maze[x][y]=='.' and isOutOfBounds(x,y,n,m))return steps;
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