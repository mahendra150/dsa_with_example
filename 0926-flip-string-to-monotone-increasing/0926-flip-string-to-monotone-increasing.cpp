class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n= s.length();
        
        vector<int> dp(n,0);
        
        int onesCount=0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='1'){
                
                onesCount+= 1;
                dp[i]= (i==0?0:dp[i-1]);
            }
            else{
                
                auto possibleAns= 1 + (i==0?0:dp[i-1]);
                
                dp[i]= min(possibleAns,onesCount);
            }
        }
        
        return dp[n-1];
    }
};