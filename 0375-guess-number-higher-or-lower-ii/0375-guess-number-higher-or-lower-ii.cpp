class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(int start,int end,int n){
        //base case
        if(start>end)return INT_MIN;
        if(start==end)return 0;
        
        //recursive case
        if(dp[start][end] != (-1))return dp[start][end];
        
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            ans=min(ans,i+ max(dfs(start,i-1,n), dfs(i+1,end,n)));
        }
        
        return dp[start][end]=ans;
    }
    int getMoneyAmount(int n) {
        
        dp.resize(n+1,vector<int>(n+1,-1));
        
        int start=1,end=n;
        
        
        return dfs(start,end,n);
    }
};