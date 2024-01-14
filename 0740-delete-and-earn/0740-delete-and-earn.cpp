class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int size= *max_element(nums.begin(),nums.end());
        vector<int> sum(size+1);
        
        sum[0]=0;
        for(auto val:nums){
            
            sum[val]+=val;
        }
        
        //Apply House Robber Logic
        
        vector<int> dp(size+1);
        int n= dp.size();
        dp[0]=0;
        dp[1]=sum[1];
        
        for(int i=2;i<n;i++){
            
            int option1= sum[i] + dp[i-2];
            int option2= dp[i-1];
            
            dp[i]=max(option1,option2);
        }
        
        return dp[n-1];
        
        
        
    }
};