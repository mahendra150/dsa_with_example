typedef pair<int,int> node;
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n= nums.size();
        
        vector<int> dp(n,0);
        
        deque<node> dq;
        int res=INT_MIN;
        
        for(int i=0;i<n;i++){
            
            if(dq.front().first==i-k-1)dq.pop_front();
            
            int maxSum = max(0, dq.empty() ? 0: dq.front().second);
            
            dp[i]= nums[i] + maxSum;
            res=max(res,dp[i]);
            
            while(!dq.empty() and dp[i]>dq.back().second)dq.pop_back();
            
            dq.push_back({i,dp[i]});
            
        }
        
        return res;
    }
};