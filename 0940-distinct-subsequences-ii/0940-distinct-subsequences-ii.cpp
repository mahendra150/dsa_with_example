class Solution {
public:
    const int mod= 1e9 + 7;
    int distinctSubseqII(string s) {
        int n= s.length();
        
        vector<long long int> dp(n,1);
        long long int res=0;
        
       for(int i=0;i<n;i++){
           
           for(int j=0;j<i;j++){
               
               if(s[i] != s[j])dp[i]+= dp[j];
               dp[i]%= mod;
           }
           
           res+= dp[i];
           res%= mod;
       }
        
        return res;
    }
};