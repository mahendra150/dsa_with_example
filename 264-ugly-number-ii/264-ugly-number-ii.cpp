class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        dp[0]=1;
       // dp[1]=1;
        int idx2=0,idx3=0,idx5=0;
        for(int i=1;i<=n;i++)
        {
            int val2=dp[idx2]*2;
            int val3=dp[idx3]*3;
            int val5=dp[idx5]*5;
            int minVal=min({val2,val3,val5});
            dp[i]=minVal;
            if(minVal==val2)idx2++;
            if(minVal==val3)idx3++;
            if(minVal==val5)idx5++;
        }
        return dp[n-1];
        
    }
};
