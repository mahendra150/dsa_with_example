class Solution {
public:
    unordered_map<int,pair<int,int>> bitRepresentation= {
        {0,{0,0}},
        {1,{1,0}},
        {2,{0,1}},
        {3,{1,1}}
    };
    
    void convertCell(int i,int j,vector<vector<int>> &board,bool live){
        
        if(board[i][j]==0 and live)board[i][j]=2;
        else if(board[i][j]==1 and live)board[i][j]=3;
        else if(board[i][j]==0 and !live)board[i][j]=0;
        else if(board[i][j]==1 and !live)board[i][j]=1;
        
    }
    int checkOriginal(int i,int j,vector<vector<int>> &board){
        int n=board.size();
        int m=board[0].size();
        
        if(i<0 or i>=n or j<0 or j>=m)return 0;
        
        int currentValue=board[i][j];
        int originalValue=bitRepresentation[currentValue].first;
        int newValue=bitRepresentation[currentValue].second;
        
        return originalValue;
    }
    int liveNbrCells(int i,int j,vector<vector<int>> &board){
        int left=checkOriginal(i,j-1,board);
        int right=checkOriginal(i,j+1,board);
        int top=checkOriginal(i-1,j,board);
        int bottom=checkOriginal(i+1,j,board);
        int d1=checkOriginal(i-1,j-1,board);
        int d2=checkOriginal(i-1,j+1,board);
        int d3=checkOriginal(i+1,j+1,board);
        int d4=checkOriginal(i+1,j-1,board);
        
        return left+right+top+bottom+d1+d2+d3+d4;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool live=false;
                int count=0;
                count+=liveNbrCells(i,j,board);
                if((board[i][j]==1) and (count==2 or count==3)){
                    live=true;
                    convertCell(i,j,board,live);
                } 
                else if((board[i][j]==1) and (count>3)){
                    live=false;
                    convertCell(i,j,board,live);
                }
                else if((board[i][j]==0) and (count==3)){
                    live=true;
                    convertCell(i,j,board,live);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currentValue=board[i][j];
                int newValue=bitRepresentation[currentValue].second;
                board[i][j]=newValue;
            }
        }
        
        
        
    }
};