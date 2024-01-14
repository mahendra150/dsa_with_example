class Solution {
public:
    unsigned int dp[501][501];
    int mod=1e9+7;
    int dfs(int pos,int n,int steps){
        //base case
        if(pos<0 or pos>=n)return 0;    //out of bounds
        
        if(steps==0 and pos==0)return 1;
        if(steps==0 and pos!=0)return 0;
        //recursive case
        if(dp[pos][steps]!=(-1))return dp[pos][steps];
        
        unsigned int option1=dfs(pos+1,n,steps-1);
        unsigned int option2=dfs(pos-1,n,steps-1);
        unsigned int option3=dfs(pos,n,steps-1);
        
        return dp[pos][steps]=(option1+option2+option3)%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,(-1),sizeof(dp));
        
        int pos=0;
        
        return dfs(pos,arrLen,steps);
    }
};