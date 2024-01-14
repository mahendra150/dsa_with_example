typedef pair<int,int> node;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        deque<node> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        q.push_back({0,0});
        dist[0][0]= 0;
        
        while(!q.empty()){
            
            auto val= q.front();
            q.pop_front();
            
            auto curx= val.first;
            auto cury= val.second;
            
            for(int k=0;k<4;k++){
                
                auto x= curx + dx[k];
                auto y= cury + dy[k];
                auto sign= grid[curx][cury];
                
                if(x>=0 and x<n and y>=0 and y<m){
                    
                    int weight=0;
                    
                    //Checking if we need to change the arrow of the direction (cost)
                    if(k+1==sign)weight=0;
                    else weight= 1;
                    
                    if(dist[curx][cury] + weight < dist[x][y]){
                        
                        dist[x][y]= dist[curx][cury] + weight;
                        
                        // (0-1)BFS Step
                        
                        if(weight==0)q.push_front({x,y});
                        
                        else q.push_back({x,y});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
        
    }
};