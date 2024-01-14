class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(int e,int f){
        
        //base case
        if(e==1)return dp[e][f]= f;
        if(f==0 or f==1)return dp[e][f]= f;
        
        //recursive case
        if(dp[e][f] != (-1))return dp[e][f];
        
        int start=1, end=f;
        
        // Break--> Go down
        // wontBreak--> Go up
        int ans= INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            int Break= dfs(e-1,mid-1);
            
            int wontBreak= dfs(e,f-mid);
            
            if(Break>wontBreak){
                end= mid-1;
            }
            else start= mid+1;
            
            ans=min(ans,1 + max(Break,wontBreak));
        }
        
        return dp[e][f]= ans;
    }
    int superEggDrop(int k, int n) {
        int e=k;
        
        dp.resize(e+1,vector<int>(n+1,-1));
        return dfs(e,n);
        
    }
};