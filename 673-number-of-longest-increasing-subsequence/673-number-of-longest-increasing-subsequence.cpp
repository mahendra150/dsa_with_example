class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,1);
        vector<int>count(n,1);
        
        int maxLen=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    int possibleAns=dp[j]+1;
                    if(possibleAns>dp[i])
                    {
                        dp[i]=possibleAns;
                        count[i]=count[j];
                    }
                    else if(possibleAns==dp[i])count[i]+=count[j];
                }
            }
            maxLen=max(maxLen,dp[i]);
        }
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxLen)res+=count[i];
        }
        return res;
        
        
        
    }
};