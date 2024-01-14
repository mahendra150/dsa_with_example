class Solution {
public:
    unordered_map<int,bool> dp;
    bool dfs(int mask,int max,int total){
        
        //base case
        if(total<=0)return dp[mask]=false;
        
        //recursive case
        if(dp.count(mask))return dp[mask];
        
        for(int i=1;i<=max;i++){
            
            //Unused number
            if((mask & (1<<(i-1))) == 0){
                
                auto nextMove= !dfs(mask|(1<<(i-1)),max,total-i);
                if(nextMove)return dp[mask]=true;
            }
        }
        
        return dp[mask]=false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int max=maxChoosableInteger;
        int total= desiredTotal;
        
        if(total<=0)return true;
        if(max*(max+1)/2<total)return false;
        
        return dfs(0,max,total);
        
    }
};