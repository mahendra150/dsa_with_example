class Solution {
public:
    int dp[100005][2][3];
    int mod= 1e9+7;
    
    long long int dfs(int n,int aFreq,int lFreq,vector<char> &nums){
        
        //base case
        
        if(n==0)return dp[n][aFreq][lFreq]= 1;
        
        //recursive case
        if(dp[n][aFreq][lFreq] != (-1))return dp[n][aFreq][lFreq];
        
        long long int ans=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]=='A'){
                
                if(aFreq==0)ans= (ans + dfs(n-1,aFreq+1,0,nums))%mod;
            }
            else if(nums[i]=='L'){
                
                if(lFreq<2)ans= (ans + dfs(n-1,aFreq,lFreq+1,nums))%mod;
                    
            }
            else{
                
                ans= (ans + dfs(n-1,aFreq,0,nums))%mod;
            }
        }
        
        return dp[n][aFreq][lFreq]= ans;
    }
    int checkRecord(int n) {
        
        vector<char> nums;
        
        nums.push_back('A');
        nums.push_back('L');
        nums.push_back('P');
        
        memset(dp,-1,sizeof(dp));
        return dfs(n,0,0,nums);
    }
};