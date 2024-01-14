class Solution {
public:
    int dfs(int i,int j,vector<int> &values){
        //base case
        if(i+1==j)return 0;
        
        //recursive case
        if(dp[i][j] != (-1))return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            int temp= (values[i]*values[k]*values[j]) + dfs(i,k,values) + dfs(k,j,values);
            ans=min(ans,temp);
        }
        
        return dp[i][j]=ans;
    }
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        
        dp.resize(55,vector<int>(55,-1));
        
        int i=0,j=n-1;
        return dfs(i,j,values);
        
    }
};