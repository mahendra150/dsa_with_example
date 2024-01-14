class Solution {
public:
    int dp[100100][2];
    int mod=1e9+7;
    int dfs(vector<int> &nums,int indx,int freq){
        int n=nums.size();
        //base case
        if(indx==n)return freq==1;
        
        //recursive case
        if(dp[indx][freq] != (-1))return dp[indx][freq];
        
        int ans=0;
        if(freq==0){
            
            if(nums[indx]==1)ans+= dfs(nums,indx+1,1);
            else if(nums[indx]==0)ans+= dfs(nums,indx+1,0);
        }
        else if(freq==1){
            
            if(nums[indx]==0)ans= (ans + dfs(nums,indx+1,0) + dfs(nums,indx+1,1))%mod;
            else if(nums[indx]==1)ans+= dfs(nums,indx+1,1);
        }
        
        return dp[indx][freq]= ans;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        
        memset(dp,(-1),sizeof(dp));
        return dfs(nums,0,0);
    }
};