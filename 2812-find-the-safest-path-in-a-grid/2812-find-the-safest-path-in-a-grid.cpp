typedef pair<int,int> node;
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n= grid.size();
        
        queue<node> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        while(!q.empty()){
            
            auto val= q.front();
            q.pop();
            
            auto curx= val.first;
            auto cury= val.second;
            
            for(int k=0;k<4;k++){
                
                auto x= curx + dx[k];
                auto y= cury + dy[k];
                
                if(x>=0 and x<n and y>=0 and y<n){
                    
                    if(dist[curx][cury] + 1 < dist[x][y]){
                        
                        dist[x][y]= dist[curx][cury] + 1;
                        q.push({x,y});
                    }
                }
            }
        }
        
        
        priority_queue<pair<int,node>> pq;
        pq.push({dist[0][0],{0,0}});
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        int res= INT_MAX;
        visited[0][0]= true;
        while(!pq.empty()){
            
            auto val= pq.top();
            pq.pop();
            
            auto curx= val.second.first;
            auto cury= val.second.second;
            
            res=min(res,dist[curx][cury]);
            
            if(curx==n-1 and cury==n-1)return res;
            for(int k=0;k<4;k++){
                
                auto x= curx + dx[k];
                auto y= cury + dy[k];
                
                if(x>=0 and x<n and y>=0 and y<n and !visited[x][y]){
                    
                    visited[x][y]= true;
                    pq.push({dist[x][y],{x,y}});
                }
            }
        }
        
        return res;
        
        
    }
};