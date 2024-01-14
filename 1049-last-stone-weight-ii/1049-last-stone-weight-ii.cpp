class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        
        int range=0;
        for(int i=0;i<n;i++)range+=stones[i];
        
        bool dp[n+1][range+1];
        
        dp[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=range;j++){
                if(i==0 and j>0){
                    dp[i][j]=false;
                }
                else if(j==0)dp[i][j]=true;
                else{
                    dp[i][j]=dp[i-1][j] or (j-stones[i-1]>=0 and stones[i-1]!=0?dp[i-1][j-stones[i-1]]:false);
                }
                                   
            }
        }
        
        int ans=INT_MAX;
        for(int j=0;j<=range;j++){
            int s1=j;
            int s2=range-s1;
            if(dp[n][j] and s2>=s1){
                ans=min(ans,range-2*s1);
            }
        }
        
        return ans;
    }
};