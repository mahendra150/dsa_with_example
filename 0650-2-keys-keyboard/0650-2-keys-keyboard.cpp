class Solution {
public:
    vector<vector<long long unsigned int>> dp;
    
    int dfs(int l,int i,int n){
        //base case
        if(i>n)return 1e9;
        if(n==i)return 0;
        
        //recursive case
        if(dp[i][l] != (-1))return dp[i][l];
        
        //option1-> copy + paste
        
        long long unsigned int option1= 2 + dfs(i,i+i,n);
        
        //option2-> paste
        
        long long unsigned int option2= 1 + dfs(l,i+l,n);
        
        return dp[i][l]=min(option1,option2);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        
        dp.resize(1005,vector<long long unsigned int>(1005,-1));
        
        int i=1,l=1;
        return 1 + dfs(l,i,n);
    }
};