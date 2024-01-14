class Solution {
public:
    
    int dfs(int n,int target,int k,vector<vector<int>> &dp){
        //base case
        if(n==0 and target==0)return 1;
        if(n<0 or target<0)return 0;
        //recursive case
        if(dp[n][target] != (-1))return dp[n][target];
        
        int totalWays=0;
        
        for(int faceVal=1;faceVal<=k;faceVal++){
            if(target-faceVal>=0){
                totalWays= (totalWays + dfs(n-1,target-faceVal,k,dp))%1000000007;
            }
        }
        
        return dp[n][target]=totalWays;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return dfs(n,target,k,dp);
        
    }
};