class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      int n=nums.size();
        int range=0;
        for(int i=0;i<n;i++)range+=nums[i];
        int diff=target;
        int s1=(diff+range)/2;
        if(((range + diff) % 2 != 0) || (abs(diff) > range))return 0;
        vector<vector<int>>dp(n+1,vector<int>(s1+1));
        dp[0][0]=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s1;j++)
            {
                if(i==0 and j>0)dp[i][j]=0;
                else if(j==0)dp[i][j]=1;
                else 
                {
                    dp[i][j]=dp[i-1][j] + (j-nums[i-1]>=0 and nums[i-1]!=0?dp[i-1][j-nums[i-1]]:0);
                }
            }
        }
        //basically I found the count of s1's
        int count = 0;
        for(int x : nums)
            if(x == 0)
                count++;
        return (int)(pow(2,count)) * dp[n][s1];
        
        
    }
};