class Solution {
public:
   vector<vector<int>> dp;
    int endSum(string &input,int len){
        
        int sum=0;
        for(int i=len-1;i>=0;i--){
            sum+= int(input[i]);
        }
        
        return sum;
    }
    int dfs(string &s1,string &s2,int n,int m){
        //base case
        
        if(n==0 or m==0){
            if(n==0 and m==0)return 0;
            
            if(n==0)return endSum(s2,m);
            if(m==0)return endSum(s1,n);
        }
        //recursive case
        if(dp[n][m] != (-1))return dp[n][m];
        
        int ans=0;
        if(s1[n-1]==s2[m-1]){
            ans= dfs(s1,s2,n-1,m-1);
        }
        else{
            int option1= int(s1[n-1]) + dfs(s1,s2,n-1,m);
            int option2= int(s2[m-1]) + dfs(s1,s2,n,m-1);
            
            // ans= min({int(s1[n]) + dfs(s1,s2,n-1,m),int(s2[m]) + dfs(s1,s2,n,m-1)});
            ans=min(option1,option2);
        }
        
        return dp[n][m]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        
        dp.resize(1005,vector<int>(1005,-1));
        return dfs(s1,s2,n,m);
        
    }
};