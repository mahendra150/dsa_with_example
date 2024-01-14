class Solution {
public:
    vector<int> findCoordinates(int val,int n){
        
        int r= (val-1)/n;
        int c= (val-1)%n;
        
        if(r%2 != 0){
            //swapping (c) <-> (n-1-c)
            c= (n-1-c);
        }
        
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n= board.size();
        
        reverse(board.begin(),board.end());
        
        queue<int> q;
        vector<vector<bool>> visited(n,vector<bool>(n));
        int steps= 0;
        
        q.push(1);
        visited[0][0]= true;
        
       

        while(!q.empty()){
            
            int k= q.size();
            
                while(k--){
                int node= q.front();
                if(node== n*n)return steps;
                q.pop();
                //All 6 possible moves
                for(int val=1;val<=6;val++){
                    if(val+node > n*n)break;
                    auto p= findCoordinates(node+val,n);
                    auto i=p[0];
                    auto j=p[1];
                    
                    if(!visited[i][j]){
                        visited[i][j]=true;
                        //Snake or ladder
                        if(board[i][j] != (-1)){
                            q.push(board[i][j]);
                        }
                        else q.push(node+val);
                    }
                }
            }
             steps+=1;
        }
        
        return (-1);
    }
};