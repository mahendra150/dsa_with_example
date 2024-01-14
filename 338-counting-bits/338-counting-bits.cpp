class Solution {
public:
    vector<int> countBits(int n) {
        
       vector<int>ans;
        int dp[n+1];
        dp[0]=0;
        ans.push_back(dp[0]);
        for(int i=1;i<=n;i++)
        {
            int x=i;
            if(x%2==0)
            {
                dp[x]=dp[x>>1];
            }
            else 
            {
                dp[x]=dp[x>>1]+1;
            }
            
            ans.push_back(dp[i]);
        }
        return ans;
        
        
    }
};