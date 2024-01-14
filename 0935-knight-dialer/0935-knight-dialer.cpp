class Solution {
public:
    int mod=1000000007;
     unordered_map<int,vector<int>>h= {
       {0,{4,6}},
       {1,{6,8}},
       {2,{7,9}},
       {3,{4,8}},
       {4,{0,3,9}},
       {5,{}},
       {6,{0,1,7}},
       {7,{2,6}},
       {8,{1,3}},
       {9,{2,4}}
   };
    
    int dfs(int val,int n,vector<vector<int>> &dp){
        //base case
        if(n==1)return dp[n][val]=1;
        //recursive case
        if(dp[n][val] != (-1))return dp[n][val];
        
        int ans=0;
        for(auto number:h[val]){
            ans= (ans + dfs(number,n-1,dp))%mod;
        }
        
        return dp[n][val]=ans;
    }
    int knightDialer(int n) {
        int res=0;
        vector<vector<int>>dp(n+1,vector<int>(10,-1));
        
        for(int val=0;val<10;val++){
            res=(res+dfs(val,n,dp))%mod;
        }
        
        return res;
    }
};