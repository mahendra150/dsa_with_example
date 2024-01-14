class Solution {
public:
    bool dfs(int i,int j,int n,int m,string word,vector<vector<char>>& board,int indx,int count)
    {
        //base case
if(i<0 or i>=n or j<0 or j>=m or board[i][j]=='*' or board[i][j]!=word[indx])
    return false;
        
        //recursive case
        if(count==word.length())return true;
        char ch=board[i][j];
        board[i][j]='*';
        
        bool left=dfs(i,j-1,n,m,word,board,indx+1,count+1);
        bool right=dfs(i,j+1,n,m,word,board,indx+1,count+1);
        bool top=dfs(i-1,j,n,m,word,board,indx+1,count+1);
        bool bottom=dfs(i+1,j,n,m,word,board,indx+1,count+1);
        board[i][j]=ch;
        return left or right or top or bottom;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int indx=0;
        int count=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[indx])
                {
                    if(dfs(i,j,n,m,word,board,indx,count))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};