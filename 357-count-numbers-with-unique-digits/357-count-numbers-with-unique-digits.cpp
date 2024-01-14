class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        
        vector<int>dp(9,0);
        
        dp[1]=10;
        dp[2]=(9*9);
        int availableUniqueNumbers=8;
        
        for(int i=3;i<=8;i++){
            dp[i]=dp[i-1]*availableUniqueNumbers;
            availableUniqueNumbers--;
        }
        
       int res=0; 
       for(int i=1;i<=n;i++){
           res+=dp[i];
       }
        
        return res;
    }
};