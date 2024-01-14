class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,vector<vector<int>> &matrix,int n,int m){
        //base case
        if(i<0 or j<0 or i>=n or j>=m)return INT_MAX;
        if(i==0)return dp[i][j]=matrix[i][j];
        
        //recursive case
        if(dp[i][j] != (-1))return dp[i][j];
        
        int ans=INT_MAX;
        
        int opt1=dfs(i-1,j,matrix,n,m);
        int opt2=dfs(i-1,j+1,matrix,n,m);
        int opt3=dfs(i-1,j-1,matrix,n,m);
        
        ans= min({opt1,opt2,opt3}) + matrix[i][j];
        
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        dp.resize(105,vector<int>(105,-1));
        
        int i=n-1;
        
        int res=INT_MAX;
        for(int j=0;j<m;j++){
            res=min(res,dfs(i,j,matrix,n,m));
        }
        
        return res;
    }
};