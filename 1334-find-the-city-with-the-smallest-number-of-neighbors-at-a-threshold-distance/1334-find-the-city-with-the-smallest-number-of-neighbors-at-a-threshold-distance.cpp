class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        
       for(auto& node:edges){
           
           dist[node[0]][node[1]]= dist[node[1]][node[0]]= node[2];
       } 
    
       for(int i=0;i<n;i++){
           dist[i][i]=0;
       } 
        
       for(int k=0;k<n;k++){
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(dist[i][k]==INT_MAX or dist[k][j]==INT_MAX)continue;
                   if(dist[i][j]==INT_MAX)dist[i][j]= dist[i][k] + dist[k][j];
                   dist[i][j]=min(dist[i][j],dist[i][k] + dist[k][j]);
               }
           }
       }
        
        int res=0;
        int smallest=n;
          for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                
                if(dist[i][j]<=distanceThreshold)count++;
            }
            if(count<=smallest){
                res=i;
                smallest=count;
            }
        }
        
        return res;
        
    }
};