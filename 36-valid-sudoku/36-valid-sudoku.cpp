class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string>s;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char currVal=board[i][j];
                if(currVal != '.')
            {
                if(s.count(to_string(currVal)+"found in row"+to_string(i)) or s.count(to_string(currVal)+"found in column"+to_string(j)) or s.count(to_string(currVal)+"found in sub box"+to_string(i/3)+"-"+to_string(j/3)))return false;
                
                    s.insert(to_string(currVal)+"found in row"+to_string(i));
                    s.insert(to_string(currVal)+"found in column"+to_string(j));
                    s.insert(to_string(currVal)+"found in sub box"+to_string(i/3)+"-"+to_string(j/3));
               }
        }
    }
        
        return true;
        
    }
};