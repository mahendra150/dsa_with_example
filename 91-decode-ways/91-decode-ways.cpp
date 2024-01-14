class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0)return 0;
        if(s[0]=='0')return 0;
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            int opt1=s[i-1]-48;
            if(opt1>=1)dp[i]=dp[i-1];
            int opt2=(s[i-2]-48)*10 + opt1;
            if(opt2>=10 and opt2<=26)dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};