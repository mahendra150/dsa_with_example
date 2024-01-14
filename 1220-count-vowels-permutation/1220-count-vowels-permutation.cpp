class Solution {
public:
    int mod= 1e9+7;
    unordered_map<char,vector<char>>h={
        {'c',{'a','e','i','o','u'}},
        {'a',{'e'}},
        {'e',{'a','i'}},
        {'i',{'a','e','o','u'}},
        {'o',{'i','u'}},
        {'u',{'a'}}
    };
    
    int dfs(int n,char prevChar,vector<vector<int>> &dp){
        //base case
        if(n<0)return 0;
        if(n==1){
            switch(prevChar)
            {
                case 'a':
                        return 1;
                case 'e':
                        return 2;
                case 'i':
                        return 4;
                case 'o':
                        return 2;
                case 'u':
                        return 1;
                default:
                        return 5;
            }
        }
        //recursive case
        
        auto indx=prevChar-97;
        if(dp[n][indx] != (-1))return dp[n][indx];
        
        int ans=0;
        for(auto next:h[prevChar]){
            ans= (ans + dfs(n-1,next,dp))%mod;
        }
        
        return dp[n][indx]=ans%mod;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+2,vector<int>(27,-1));
        
        return dfs(n,'c',dp);
    }
};