typedef pair<int,int> node;
class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int indx,int prev,vector<node> &nums){
        int n= nums.size();
        //base case
        
        if(indx>=n)return dp[indx][prev]= nums[prev].second;
        
        //recursive case
        if(dp[indx][prev] != (-1))return dp[indx][prev];
        
        int ans= INT_MIN;
            
        //Principle of Inclusion/Exclusion
        
        //Once we exclude
        ans= dfs(indx+1,prev,nums);
        
        //Once we include
        if(nums[indx].second>=nums[prev].second)ans=max(ans,nums[prev].second + dfs(indx+1,indx,nums));
        
        return dp[indx][prev]= ans;
            
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n= scores.size();
        if(n==1)return scores[0];
        
        vector<node> nums;
        for(int i=0;i<n;i++){
            
            nums.push_back({ages[i],scores[i]});
        }
        
        sort(nums.begin(),nums.end());
        dp.resize(1005,vector<int>(1005,-1));
        
        int res=0;
        for(int i=1;i<n;i++){
            
            res=max(res,dfs(i,i-1,nums));
        }
        
        return res;
        
    }
};