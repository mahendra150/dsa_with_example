class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int indx,int number,string &s,int n){
        
        //base case
        
        if(indx==n){
            
            if(number % 25 == 0)return dp[indx][number]= 0;
            
            return dp[indx][number]= 1e9;
        }
        //recursive case
        if(dp[indx][number] != (-1))return dp[indx][number];
        
        
        // Principle Of Inclusion-Exclusion
        
        // unsigned int ans1,ans2;
        
        int digit= s[indx]-48;
            
        // Once I will Exclude
        int ans1= 1 + dfs(indx+1,number,s,n);
        
        // Once I will Include
        int ans2= dfs(indx+1,(number*10+digit)%25,s,n);
        
        
        return dp[indx][number]= min(ans1,ans2);
    }
    int minimumOperations(string num) {
        int n= num.length();
        
        dp.resize(105,vector<int>(25,-1));
        return dfs(0,0,num,n);
        
    }
};