class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)return (-1);
        
        vector<vector<int>> dist(105,vector<int>(105,INT_MAX));
        queue<pair<int,int>>q;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        if(q.empty())return (-1);
        
        
       int dx[4]={1,-1,0,0};
       int dy[4]={0,0,1,-1};
        
       while(!q.empty()){
           auto node=q.front();
           q.pop();
           
           auto curx=node.first;
           auto cury=node.second;
           
           for(int k=0;k<4;k++){
               auto x=curx+dx[k];
               auto y=cury+dy[k];
               
               if(x>=0 and x<n and y>=0 and y<n){
                   if(dist[curx][cury]+1<dist[x][y]){
                       dist[x][y]=dist[curx][cury]+1;
                       q.push({x,y});
                   }
               }
           }
       }
        
        int res=(-1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)res=max(res,dist[i][j]);
            }
        }
        
        return res;
        
    }
};