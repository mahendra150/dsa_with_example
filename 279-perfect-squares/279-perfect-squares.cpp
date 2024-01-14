class Solution {
public:
    int utility(int n,int *dp){
        //base case
        if(n==0)return dp[n]=0;
        
        if(dp[n]!=(-1))return dp[n];
        //recursive case
        int ans=INT_MAX;
        for(int j=1;j*j<=n;j++){
            int sikka=j*j;
            if(n-sikka>=0){
                int chotiAmount=n-sikka;
                int chotiAmtKeSikke=utility(chotiAmount,dp);
                if(chotiAmtKeSikke != INT_MAX){
                    ans=min(ans,chotiAmtKeSikke+1);
                }
            }
        }
        
        return dp[n]=ans;
    }
    int numSquares(int n) {
        int dp[10005];
        memset(dp,(-1),sizeof(dp));
        
        return  utility(n,dp);
        
    }
};