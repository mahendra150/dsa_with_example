// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int utility(int n,int capacity,int dp[][1005],int val[],int wt[])
    {
        //base case
        if(n==0 or capacity==0)return 0;
        //recursive case
        if(dp[n][capacity]!=(-1))return dp[n][capacity];
        int opt1=INT_MIN;
        int opt2=INT_MIN;
        if(capacity-wt[n-1]>=0)
        {
            opt1=val[n-1]+utility(n-1,capacity-wt[n-1],dp,val,wt);
        }
        opt2=utility(n-1,capacity,dp,val,wt);
        return dp[n][capacity]= max(opt1,opt2);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int capacity=W;
       int dp[1005][1005];
       memset(dp,(-1),sizeof(dp));
      return utility(n,capacity,dp,val,wt);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends