typedef pair<int,pair<int,int>> node;
class Solution {
public:
    int bfs(node &source,node &destination,vector<vector<int>> &forest){
        int n=forest.size();
        int m=forest[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<node> q;
        
        int dx[4]= {1,-1,0,0};
        int dy[4]= {0,0,-1,1};
        
        q.push(source);
        visited[source.second.first][source.second.second]= true;
        
        int steps=0;
        while(!q.empty()){
            // cout<<steps<<endl;
            
            int size=q.size();
            while(size--){
                
                auto val= q.front();
                // cout<<val.first<<endl;
                q.pop();
                if(val==destination)return steps;
                
                for(int k=0;k<4;k++){
                    
                    auto x= val.second.first + dx[k];
                    auto y= val.second.second + dy[k];
                    
                    if(x>=0 and x<n and y>=0 and y<m and forest[x][y] and !visited[x][y]){
                        
                        visited[x][y]= true;
                        q.push({forest[x][y],{x,y}});
                    }
                }
            }
            steps+=1;
        }
        
        return (-1);
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m= forest[0].size();
        vector<node> order;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(forest[i][j]>1){
                    
                    order.push_back({forest[i][j],{i,j}});
                }
            }
        }
        
        // order.push_back({0,{0,0}});
       sort(order.begin(),order.end());
        
        // for(auto i:order){
        //     cout<<i.first<<endl;
        // }
        
        // vector<vector<bool>> visited(n,vector<bool>(m,false));
        int res=0;
        
        int curr_row=0, curr_col=0;
        node source= {forest[curr_row][curr_col],{curr_row,curr_col}};
        for(int i=0;i<order.size();i++){
            
            auto destination= order[i];
            
            int subRes= bfs(source,destination,forest);
            if(subRes== (-1))return (-1);
            
            res+=subRes;
            source= destination;
            
        }
       
        
        return res;
        
    }
};