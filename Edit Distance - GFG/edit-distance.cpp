// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int utility(int n,int m,string s,string t,int dp[][105])
  {
      //base case
      if(n==0)return dp[n][m]=m;
      if(m==0)return dp[n][m]= n;
      //recursive case
      if(dp[n][m]!=(-1))return dp[n][m];
      
        if(s[n-1]==t[m-1])
        {
            return dp[n][m]=utility(n-1,m-1,s,t,dp);
        }
            int opt1=utility(n,m-1,s,t,dp);
            int opt2=utility(n-1,m,s,t,dp);
            int opt3=utility(n-1,m-1,s,t,dp);
           return dp[n][m]=1+min({opt1,opt2,opt3});
  }
    int editDistance(string s, string t) {
        int n=s.length();
        int m=t.length();
        int dp[105][105];
        memset(dp,(-1),sizeof(dp));
      return  utility(n,m,s,t,dp);
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends