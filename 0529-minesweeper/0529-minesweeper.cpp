class Solution {
public:
    bool check(int i,int j,int n,int m){
        
        return i>=0 and i<n and j>=0 and j<m;
    }
    int checkOriginal(int i,int j,vector<vector<char>> &board,int n,int m){
        
        if(check(i,j,n,m) and board[i][j]=='M')return 1;
        
        return 0;
    }
    int utility(int i,int j,vector<vector<char>> &board,int n,int m){
        
        int left=checkOriginal(i,j-1,board,n,m);
        int right=checkOriginal(i,j+1,board,n,m);
        int top=checkOriginal(i-1,j,board,n,m);
        int bottom=checkOriginal(i+1,j,board,n,m);
        int d1=checkOriginal(i-1,j-1,board,n,m);
        int d2=checkOriginal(i-1,j+1,board,n,m);
        int d3=checkOriginal(i+1,j+1,board,n,m);
        int d4=checkOriginal(i+1,j-1,board,n,m);
        
        return left+ right + top + bottom + d1 + d2 + d3+ d4;
    }
    void dfs(int i,int j,vector<vector<char>> &board,int n,int m,vector<vector<bool>> &visited){
        
        //base case
        if(!check(i,j,n,m) or board[i][j]=='M' or visited[i][j])return;
        
        
        //recursive case
        
        visited[i][j]= true;
        
        if(board[i][j]=='E'){
            
            auto count= utility(i,j,board,n,m);
            if(!count){
                board[i][j]= 'B';
                
                dfs(i+1,j,board,n,m,visited);
                dfs(i-1,j,board,n,m,visited);
                dfs(i,j+1,board,n,m,visited);
                dfs(i,j-1,board,n,m,visited);
                dfs(i-1,j-1,board,n,m,visited);
                dfs(i-1,j+1,board,n,m,visited);
                dfs(i+1,j+1,board,n,m,visited);
                dfs(i+1,j-1,board,n,m,visited);
            }
            else{
                
                char ch= count + 48;
                board[i][j]= ch;
            }
        }
    
        
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n= board.size();
        int m= board[0].size();
        
        int startRow= click[0];
        int startCol= click[1];
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        if(board[startRow][startCol]=='M'){
            board[startRow][startCol]='X';
            return board;
        }
        
        dfs(startRow,startCol,board,n,m,visited);
        
        return board;
        
    }
};