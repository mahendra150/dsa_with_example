class Solution {
public:
    const int mod= 1e9 + 7;
    int countOrders(int n) {
        
        int X= (2*n);
        vector<long long int> dp(1005,1);
        
        dp[X+2]= 1;
        while(X){
            
            long long int numberOfValidChoices= ((X%mod)*((X-1)%mod))/2;
            dp[X]= (dp[X+2]*numberOfValidChoices)%mod;
            X-=2;
        }
        
        return dp[2]%mod;
    }
};