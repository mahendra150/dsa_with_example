class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        
        parent.resize(n+1,0);
        size.resize(n+1,0);
        
        for(int i=0;i<=n;i++){
            
            parent[i]= i;
            size[i]= 1;
        }
    }
    
    int findPar(int node){
        if(parent[node]==node)return node;
        
        return parent[node]= findPar(parent[node]);
    }
    
    void unionBySize(int u,int v){
        
        u= findPar(u);
        v= findPar(v);
        if(u==v)return;
        
        if(size[u]<size[v]){
            
            parent[u]= v;
            size[v]+= size[u];
        }
        else{
            
            parent[v]= u;
            size[u]+= size[v];
        }
    }
    
};
class Solution {
public:
    bool isValid(int i,int j,int n){
        
        if(i>=0 and i<n and j>=0 and j<n)return true;
        
        return false;
    }
    int makingLargest(vector<vector<int>> &grid){
        int n= grid.size();
        
        DisjointSet ds(n*n);
        
        //Step:1 -->   Join Indivisual Islands
        
        int dx[4]= {1,-1,0,0};
        int dy[4]= {0,0,1,-1};
        
        for(int curx=0;curx<n;curx++){
            
            for(int cury=0;cury<n;cury++){
                
                if(grid[curx][cury]==0)continue;
                
                for(int k=0;k<4;k++){
                
                    int x= curx + dx[k];
                    int y= cury + dy[k];
                    
                    if(isValid(x,y,n) and grid[x][y]==1){
                        
                        int nodeNo= (curx*n) + cury;
                        int adjNodeNo= (x*n) + y;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        
        //Step:2  -->  Join the neighbouring Islands
        
        int mx= 0;
        for(int curx=0;curx<n;curx++){
            
            for(int cury=0;cury<n;cury++){
                
                if(grid[curx][cury]==1)continue;
                
                set<int> components;
                
                for(int k=0;k<4;k++){
                    
                    int x= curx + dx[k];
                    int y= cury + dy[k];
                    
                    if(isValid(x,y,n) and grid[x][y]==1){
                        
                        int adjNode= (x*n) + y;
                        components.insert(ds.findPar(adjNode));
                        
                    }
                }
                
                int totalArea= 0;
                for(auto island: components){
                    
                    totalArea+= ds.size[island];
                }
                
                totalArea+=1;
                mx=max(mx,totalArea);
            }
        }
        
        for(int i=0;i<n*n;i++){
            
            mx=max(mx,ds.size[i]);
        }
        
        return mx;
        
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        return makingLargest(grid);
    }
};