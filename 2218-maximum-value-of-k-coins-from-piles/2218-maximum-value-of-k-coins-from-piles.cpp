class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int n,int k,vector<vector<int>> &piles){
        
        //base case
        
        if(n==0 or k==0)return dp[n][k]= 0;
        
        
        //recursive case
        if(dp[n][k] != (-1))return dp[n][k];
        
        int ans= INT_MIN;
        
        // Once I will Exclude
        
        ans=max(ans,dfs(n-1,k,piles));
        
        //Once I will Include
        
        int sum=0;
        for(int j=0;j<piles[n-1].size();j++){
            
            sum+= piles[n-1][j];
            auto currElements= j+1;
            if(k-currElements>=0){
                
                ans=max(ans, sum + dfs(n-1,k-currElements,piles));
            }
        }
        
        return dp[n][k]= ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n= piles.size();
        
        dp.resize(1005,vector<int>(2005,-1));
        return dfs(n,k,piles);
        
    }
};