// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range=0;
	    for(int i=0;i<n;i++)range+=arr[i];
	    
	    bool dp[n+1][range+1];
	    dp[0][0]=true;
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=range;j++)
	        {
	            if(i==0 and j>0)dp[i][j]=false;
	           else  if(j==0)dp[i][j]=true;
	            else
	            {
	                dp[i][j]=dp[i-1][j] or (j-arr[i-1]>=0?dp[i-1][j-arr[i-1]]:false);
	            }
	        }
	    }
	    int ans=INT_MAX;
	    for(int j=0;j<=range;j++)
	    {
	        int s1=j;
	        int s2=range-s1;
	        if(dp[n][j]==true and s2>=s1)
	        {
	            ans=min(ans,range-(2*s1));
	        }
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends