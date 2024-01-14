// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int capacity=W;
        int n=N;
        int dp[n+1][capacity+1];
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=capacity;j++)
            {
                if(i==0 and j>0)dp[i][j]=0;
                else if(j==0)dp[i][j]=0;
                else
                {
                    int opt1=dp[i-1][j];
                    int opt2=(j-wt[i-1]>=0?dp[i][j-wt[i-1]] + val[i-1]:0);
                    dp[i][j]=max(opt1,opt2);
                }
            }
        }
        return dp[n][capacity];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends