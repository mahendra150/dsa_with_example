class Solution {
public:
    int mod=1e9+7;
    int dfs(int n,int prevRoll,int freq,vector<vector<vector<unsigned long long int>>> &dp,vector<int> &rollMax){
        //base case
        if(n==0)return 1;
        
        //recursive case
        if(dp[n][prevRoll][freq] != (-1))return dp[n][prevRoll][freq];
        
        unsigned long long int ans=0;
        
        for(int faceVal=1;faceVal<=6;faceVal++){
            if(faceVal==prevRoll){
                if(freq<rollMax[prevRoll-1]){
                    ans= (ans + dfs(n-1,faceVal,freq+1,dp,rollMax)%mod);
                }
            }
            else{
                ans= (ans + dfs(n-1,faceVal,1,dp,rollMax)%mod);
            }
        }
        
        return dp[n][prevRoll][freq]=ans%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        //3D-DP
        vector<vector<vector<unsigned long long int>>>dp(n+1,vector<vector<unsigned long long  int>>(7,vector<unsigned long long int>(16,-1)));
        
        return dfs(n,0,0,dp,rollMax);
        
    }
};