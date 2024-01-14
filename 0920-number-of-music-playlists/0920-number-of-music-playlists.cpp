class Solution {
public:
    const int mod= 1e9 + 7;
    vector<vector<long long>> dp;
    long long dfs(int goal,int unique,int n,int k){
        
        //base case
        
       if (goal == 0) {
		return dp[unique][goal]= unique == n ? 1 : 0;
	}
        
        //recursive case
        if(dp[unique][goal] != (-1))return dp[unique][goal];
        
        //   Principle of Inclusion / Exclusion
        
       long long ans=0;
        
        // Once I will Include a unique Number
        
        ans= (ans + ((n-unique)*dfs(goal-1,unique+1,n,k))%mod)%mod;
        
        
        // Oncle I will Exlucde a unique Number  --> Repeat a number
        
        if(unique>k)ans= (ans +  ((unique-k)*dfs(goal-1,unique,n,k))%mod)%mod;
        
        
        return dp[unique][goal]= ans % mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        
        dp.resize(105,vector<long long>(105,-1));
        return dfs(goal,0,n,k);
    }
};