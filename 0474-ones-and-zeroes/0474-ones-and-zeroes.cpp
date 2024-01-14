class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int dfs(int i,int n,int m,vector<pair<int,int>> &nums){
        //base case
        if(i==nums.size())return 0;
        //recursive case
        if(dp[i][n][m] != (-1))return dp[i][n][m];
        
        //Either I (include or exclude)
        
        int include=0;
        if(n-nums[i].first>=0 and m-nums[i].second>=0){
            include= 1 + dfs(i+1,n-nums[i].first,m-nums[i].second,nums);
        }
        
        int exclude= 0 + dfs(i+1,n,m,nums);
        
        int ans;
        ans=max(include,exclude);
        
        return dp[i][n][m]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> nums;
        
        //Pre-Computation
        
        for(auto i:strs){
            int ones=0;
            int zeroes=0;
            for(auto ch:i){
                if(ch=='1')ones++;
                else zeroes++;
            }
            
            nums.push_back({ones,zeroes});
        }
        
        dp.resize(strs.size(),vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        int i=0;
        
        return dfs(i,n,m,nums);
    }
};