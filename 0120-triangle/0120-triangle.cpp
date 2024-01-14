class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(int i,int j,vector<vector<int>> &triangle){
        int n=triangle.size();
        int m=triangle[i].size();
        
        //base case
        if(i>=n or j>=m)return INT_MAX;
        if(i==n-1)return dp[i][j]=triangle[i][j];
        
        //recursive case
        if(dp[i][j] != (-1))return dp[i][j];
        
        int ans=INT_MAX;
        
        int opt1=dfs(i+1,j,triangle);
        int opt2=dfs(i+1,j+1,triangle);
        
        ans= min(opt1,opt2) + triangle[i][j];
        
        return dp[i][j]=ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        dp.resize(205,vector<int>(205,-1));
        
        int i=0,j=0;
        return dfs(i,j,triangle);
        
    }
};