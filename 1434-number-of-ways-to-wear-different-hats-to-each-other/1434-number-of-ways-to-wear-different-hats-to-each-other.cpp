class Solution {
public:
    int mod=1e9+7;
    vector<long long int> H;
    vector<vector<long long int>> dp;
    // int n;
    int dfs(int mask,int hat,int n){
        
        //base case
        
        if(mask==((1<<n)-1))return dp[hat][mask]= 1;
        if(hat>40)return 0;
        
        //recursive case
        if(dp[hat][mask] != (-1))return dp[hat][mask];
        
        long long int ans=0;
        for(int i=0;i<n;i++){
            
            if((mask & (1<<i))==0 and (H[hat] & (1<<i))){
                ans=(ans + dfs(mask|(1<<i),hat+1,n)) % mod;;
            }
        }
        
        ans= (ans + dfs(mask,hat+1,n)) % mod;
        
        return dp[hat][mask]= ans;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        
        H.resize(45,0);
        dp.resize(45,vector<long long int>(2048,-1));
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<hats[i].size();j++){
                
                auto hat= hats[i][j];
                H[hat]|= (1<<i);
            }
        }
        
        // for(int i=0;i<H.size();i++){
        //     cout<<H[i]<<endl;
        // }
        
        int mask=0,hat=1;
        return dfs(mask,hat,n);
        
    }
};