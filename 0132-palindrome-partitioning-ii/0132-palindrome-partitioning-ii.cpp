class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(int left,int right,string &str){
        
        while(left<right){
            
            if(str[left++] != str[right--])return false;
        }
        
        return true;
    }
    int dfs(int start,int end,string &str){
        
        //base case
        if(start==end)return dp[start][end]= 0;
        if(isPalindrome(start,end,str))return dp[start][end]= 0;
        
        //recursive case
        
        if(dp[start][end] != (-1))return dp[start][end];
        
        int ans= INT_MAX;
        for(int mid=start;mid<=end;mid++){
            
            if(isPalindrome(start,mid,str))ans=min(ans,1 + dfs(mid+1,end,str));
        }
        
        return dp[start][end]= ans;
    }
    int minCut(string s) {
        int n= s.length();
        
        dp.resize(2005,vector<int>(2005,-1));
        return dfs(0,n-1,s);
    }
};