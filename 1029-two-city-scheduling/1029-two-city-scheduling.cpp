class Solution {
public:
    vector<vector<int>>dp;
    
    int dfs(int n,int a,int b,vector<vector<int>> &costs){
        
        //base case
        if(n==0 and a==0 and b==0)return dp[a][b]= 0;
        if(a<0 or b<0)return 100000;
        //recursive case
       if(dp[a][b] != (-1))return dp[a][b];
        
        int opt1,opt2;
        
        //Once I will send to (cityA)
        opt1= costs[n-1][0] + dfs(n-1,a-1,b,costs);
        
        //Once I will send to (cityB)
        opt2= costs[n-1][1] + dfs(n-1,a,b-1,costs);
        
        return dp[a][b]= min({opt1,opt2});
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        
        dp.resize(100,vector<int>(100,-1));
        
        int a=n/2,b=n/2;
        
        return dfs(n,a,b,costs);
        
    }
};