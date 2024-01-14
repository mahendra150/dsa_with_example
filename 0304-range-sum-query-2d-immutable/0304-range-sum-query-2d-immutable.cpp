class NumMatrix {
public:
     vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        
       dp.resize(n+1,vector<int>(m+1));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                dp[i][j]= dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        row1+=1,col1+=1,row2+=1,col2+=1;
        
        int bottomRight= dp[row2][col2];
        int top= dp[row1-1][col2];
        int left= dp[row2][col1-1];
        int topLeft= dp[row1-1][col1-1];
        
        return bottomRight - top - left + topLeft;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */