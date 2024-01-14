class Solution {
public:
    vector<vector<double>> dp;
    
    double dfs(double poured,int i,int j){
        
        //base case
        if(i<0 or j<0 or j>i)return 0.0;
        if(i==0 and j==0)return dp[i][j]= poured;
        
        //recursive case
        if(dp[i][j] != (-1))return dp[i][j];
        
        double option1= dfs(poured,i-1,j);
        double option2= dfs(poured,i-1,j-1);
        
        return dp[i][j]= max((option1-1.0),0.0)/2.0 + max((option2-1.0),0.0)/2.0;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        
        // if(query_row==0 and query_glass==0)return poured-1;
        dp.resize(105,vector<double>(105,-1));
        
        int n= dp.size();
        int m= dp[0].size();
        
        
        return min(1.0,dfs(poured,query_row,query_glass));
    }
};