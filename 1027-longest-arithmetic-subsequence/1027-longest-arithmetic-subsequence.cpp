class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>>dp(2000,vector<int>(n,0));
         int res=2;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=nums[j]-nums[i]+1000;
                
                int possibleAns=dp[diff][i]+1;
                dp[diff][j]=max({dp[diff][j],2,possibleAns});
                res=max(res,dp[diff][j]);
            }
        }
        
        return res;
        
        
    }
};