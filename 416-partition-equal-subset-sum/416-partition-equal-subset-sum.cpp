class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2!=0)return false;
        
        sum=sum/2;
        //now we search for one partition
        //if p1 exists then p2 surely exists
        //p1=p2=sum/2
        
        bool dp[n+1][sum+1];
        dp[0][0]=true;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0 and j>0)dp[i][j]=false;
                else if(j==0)dp[i][j]=true;
                else
                {
                    dp[i][j]=dp[i-1][j] or (j-nums[i-1]>=0?dp[i-1][j-nums[i-1]]:false);
                }
            }
        }
        return dp[n][sum];
        
        
        
    }
};