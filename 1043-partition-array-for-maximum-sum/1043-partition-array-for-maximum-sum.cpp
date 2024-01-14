class Solution {
public:
    vector<int> dp;
    int dfs(int indx,int k,vector<int> &nums,int n){
        
        //base case
        
        if(indx>=n)return dp[indx]= 0;
        //recursive case
        if(dp[indx] != (-1))return dp[indx];
        
        int ans=0;
        int maxElement=0;
        for(int i=indx;i<indx+k and i<n;i++){
            
            maxElement=max(maxElement,nums[i]);
            
            ans=max(ans,maxElement*(i-indx+1) + dfs(i+1,k,nums,n));
        }
        
        return dp[indx]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        
        dp.resize(505,-1);
        return dfs(0,k,arr,n);
    }
};