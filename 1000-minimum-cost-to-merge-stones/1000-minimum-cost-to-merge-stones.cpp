class Solution {
public:
    vector<int>prefix;
    int dp[32][32];
    
    int dfs(int left,int right,int k){
        //base case
        if(left==right)return 0;
        int l=(right-left);
        //recursive case
        if(dp[left][right] != (-1))return dp[left][right];
        
        int ans=1e9;
        for(int i=left;i<right;i+=(k-1)){
                ans=min(ans,dfs(left,i,k) + dfs(i+1,right,k));
        }
        
        //Mergeable condition
        if((l)%(k-1)==0){
            ans+=(prefix[right+1]-prefix[left]);
        }
        
        return dp[left][right]=ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();

        memset(dp,(-1),sizeof(dp));
        
        int left=0,right=n-1;
        
        if((n-1)%(k-1) != 0)return -1;
        
        prefix.push_back(0);
        for(int i=0;i<n;i++){
            prefix.push_back(stones[i]+prefix.back());
        }
        
        return dfs(left,right,k);
    }
};