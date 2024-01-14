class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
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
                
                if(x>=0 and x<n and y>=0 and y<m){
                    if(dist[curx][cury]+1<dist[x][y]){
                        dist[x][y]=dist[curx][cury]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return dist;
        
    }
};