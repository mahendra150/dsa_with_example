class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n= s.length();
        
        vector<int> dp(n,0);
        int zeros=0;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='0'){
                
                zeros+=1;
                dp[i]= i==0?0:dp[i-1];
            }
            
            else{
                
                if(i>=1 and s[i-1]=='1' and zeros)dp[i]+= (1 + dp[i-1]);
                
                else if(i>=1 and s[i-1]=='0'){
                    
                    int possibleAns= 1 + dp[i-1];
                    dp[i]=max(possibleAns,zeros);
                }
            }
        }
        
        return dp[n-1];;
        
    }
};