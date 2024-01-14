class Solution {
public:
    double dp[200][200];
    double dfs(int a,int b){
        //base case
        if(a<=0 and b<=0)return 0.5;
        if(a<=0)return 1;
        if(b<=0)return 0;
        
        //recursive case
        if(dp[a][b] > 0)return dp[a][b];
        
        dp[a][b]=0.25*(dfs(a-4,b) + dfs(a-3,b-1) + dfs(a-2,b-2) + dfs(a-1,b-3));
        
        return dp[a][b];
    }
    double soupServings(int n) {
        //Big N case
        if(n>4800)return 1.0;
        
       return dfs((n+24)/25,(n+24)/25);
    }
};