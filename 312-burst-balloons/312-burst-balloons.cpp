class Solution {
public:
    int utility(int left,int right,int dp[][305],vector<int>&nums){
        //base case
        if(left>right)return 0;
        //recursive case
        if(dp[left][right]!=(-1))return dp[left][right];
        
        int result=0;
        int coins=0;
        for(int i=left;i<=right;i++){
            coins=(nums[left-1]*nums[i]*nums[right+1]);
            coins+= utility(left,i-1,dp,nums) + utility(i+1,right,dp,nums);
            result=max(result,coins);
        }
        
        return dp[left][right]=result;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        
        int n=nums.size();
        
        int dp[305][305];
        memset(dp,(-1),sizeof(dp));
        
        int left=1,right=n-2;
        
       return utility(left,right,dp,nums);
        
    }
};