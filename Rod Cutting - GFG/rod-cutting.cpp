// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int length=n;
        int dp[n+1][length+1];
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=length;j++)
            {
                if(i==0 and j>0)dp[i][j]=0;
                else if(j==0)dp[i][j]=0;
                else
                {
                    int opt1=dp[i-1][j];
                    int opt2=(j-i>=0?dp[i][j-i]+price[i-1]:0);
                    dp[i][j]=max(opt1,opt2);
                }
            }
        }
        return dp[n][length];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends