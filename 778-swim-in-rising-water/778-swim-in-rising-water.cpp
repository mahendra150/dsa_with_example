typedef pair<int,pair<int,int>>node;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)return 0;
        
        priority_queue<node,vector<node>,greater<node>>q;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        q.push({grid[0][0],{0,0}});
        
        int res=INT_MIN;
        res=max(grid[0][0],grid[n-1][n-1]);
        
        while(!q.empty()){
            auto val=q.top();
            q.pop();
            
            res=max(res,val.first);
            
            for(int i=0;i<4;i++){
                auto x=dx[i]+val.second.first;
                auto y=dy[i]+val.second.second;
                
                if(x<0 or x>=n or y<0 or y>=n or visited[x][y])continue;
                if(x==n-1 and y==n-1)return res;
                
                visited[x][y]=true;
                q.push({grid[x][y],{x,y}});
            }
        }
        
        return -1;
        
    }
};