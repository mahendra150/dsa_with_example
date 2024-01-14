class Solution {
public:
    vector<int> dp;
    
    int dfs(int si,vector<int> &days,vector<int> &costs){
        int n=days.size();
        
        //base case
        if(si>=n)return 0;
        
        //recursive case
        if(dp[si] != (-1))return dp[si];
        
        int cost_day= costs[0] + dfs(si+1,days,costs);
        
        int i;
        
        for(i=si;i<n and days[i]<days[si]+7;i++);
        int cost_week= costs[1] + dfs(i,days,costs);
        
        for(i=si;i<n and days[i]<days[si]+30;i++);
        int cost_month= costs[2] + dfs(i,days,costs);
        
        int ans=INT_MAX;
        ans= min({cost_day,cost_week,cost_month});
        
        return dp[si]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        
        dp.resize(400,-1);
        
        //si -> start index
        int si=0;
        
        return dfs(si,days,costs);
        
    }
};