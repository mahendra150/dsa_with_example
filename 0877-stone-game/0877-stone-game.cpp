class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int left,int right,vector<int> &piles){
        
        //base case
        if(left==right-1)return dp[left][right]= max(piles[left],piles[right]);
        
        //recursive case
        if(dp[left][right] != (-1))return dp[left][right];
        
        int option1= piles[left] + max(dfs(left+2,right,piles),dfs(left+1,right-1,piles));
        
        int option2= piles[right] + max(dfs(left+1,right-1,piles),dfs(left,right-2,piles));
        
        return dp[left][right]= max(option1,option2);
        
    }
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        
        dp.resize(505,vector<int>(505,-1));
        return dfs(0,n-1,piles);
    }
};