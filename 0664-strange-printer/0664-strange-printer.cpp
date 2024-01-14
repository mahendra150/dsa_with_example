class Solution {
public:
    vector<vector<int>> dp;
    int dfs(string &s,int left,int right){
        
        //base case
        if(left>right)return 0;
        
        //recursive case
        if(dp[left][right] != (-1))return dp[left][right];
        
        int tmpl= left;
        while(left+1<=right and s[left]==s[left+1]){
            
            left++;
        }
        
        
        int ans= 1 + dfs(s,left+1,right);
        
        for(int mid=left+1;mid<=right;mid++){
            
            if(s[left]==s[mid]){
                
                ans=min(ans,dfs(s,left+1,mid-1) + dfs(s,mid,right));
                
            }
            
        }
        
        
        return dp[left][right]= ans;
    }
    int strangePrinter(string s) {
        int n= s.length();
        
        dp.resize(105,vector<int>(105,-1));
        return dfs(s,0,n-1);
    }
};