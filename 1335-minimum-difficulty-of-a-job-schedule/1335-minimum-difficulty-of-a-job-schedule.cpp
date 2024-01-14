class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(vector<int> &jobDifficulty,int indx,int d){
        int n= jobDifficulty.size();
        //base case
        
        if(d==1){
            
            int maxElement= INT_MIN;
            for(int i=indx;i<n;i++){
                
                maxElement=max(maxElement,jobDifficulty[i]);
            }
            
            return  dp[indx][d]= maxElement;
        }
        //recursive case
        if(dp[indx][d] != (-1))return dp[indx][d];
        
        
        int result= INT_MAX;
        int maxElement= INT_MIN;
        for(int i=indx;i<=n-d;i++){
            
            maxElement=max(maxElement,jobDifficulty[i]);
            result=min(result,maxElement + dfs(jobDifficulty,i+1,d-1));
        }
        
        return dp[indx][d]= result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n= jobDifficulty.size();
        if(n<d)return (-1);
        
        dp.resize(305,vector<int>(15,-1));
        
        return dfs(jobDifficulty,0,d);
    }
};