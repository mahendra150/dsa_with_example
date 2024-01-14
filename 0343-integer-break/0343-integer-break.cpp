class Solution {
public:
    vector<int> dp;
    int dfs(int n,int k){
        //base case
        if(n==0 ){
            if(k>=2){
                return dp[n]=1;
            }
            else return 0;
        }
        
        //recursive case
        if(dp[n] != (-1))return dp[n];
        
        int ans= INT_MIN;
        for(int j=1;j<=n;j++){
            int sikka= j;
            if(n-sikka>=0){
                int chotiAmount= n-sikka;
                int chotiAmountKeSikke= dfs(chotiAmount,k+1);
                if(chotiAmountKeSikke != INT_MIN){
                    ans= max(ans,chotiAmountKeSikke*sikka);
                }
            }
        }
        
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        
        int k=0;
        dp.resize(60,-1);
        return dfs(n,k);
        
    }
};