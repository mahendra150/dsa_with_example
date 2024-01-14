class Solution {
public:
    vector<vector<int>> dp;
    bool utility(int start,int end,vector<int> &nums,int m){
        
        int sum=0;
        for(int i=start;i<=end;i++){
            
            sum+= nums[i];
        }
        
        if(sum>=m)return true;
        
        return false;
    }
    bool dfs(int start,int end,vector<int> &nums,int m){
        
        //base case
        
        if(start==end)return dp[start][end]= true;
        
        if(!utility(start,end,nums,m))return dp[start][end]= false;
        
        //recursive case
        if(dp[start][end] != (-1))return dp[start][end];
        
        auto ans= false;
        for(int mid=start;mid<end;mid++){
            
            auto left= dfs(start,mid,nums,m);
            auto right= dfs(mid+1,end,nums,m);
            
            if(left and right){
                
                ans= true;
            }
        }
        
        return dp[start][end]= ans;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int n= nums.size();
        if(n<=2)return true;
        
        dp.resize(105,vector<int>(105,-1));
        return dfs(0,n-1,nums,m);
        
    }
};