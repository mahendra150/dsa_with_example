class Solution {
public:
    vector<vector<double>> dp;
    double dfs(int indx,int d,vector<int> &nums,int n){
        
        //base case
        
        if(indx>=n)return 0;
        if(d==0)return dp[indx][d]= 0;
        
        if(d==1){
            
            double prefixSum=0;
            for(int i=indx;i<n;i++){
                
                prefixSum+= nums[i];
            }
            
            return  prefixSum/(n-indx);
            
        }
        //recursive case
        if(dp[indx][d] != (-1))return dp[indx][d];
        
        double prefixSum=0;
        double ans= INT_MIN;
        for(int i=indx;i<=n-d;i++){
            
            prefixSum+= nums[i];
            double average= prefixSum/(i-indx+1);
            
            ans=max(ans, average + dfs(i+1,d-1,nums,n));
        }
        
        return dp[indx][d]= ans;
        
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n= nums.size();
        
        dp.resize(105,vector<double>(105,-1));
        return dfs(0,k,nums,n);
    }
};