// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    for(int i=0;i<n;i++)
	    {
	        dp[i]=arr[i];
	    }
	    for(int i=1;i<n;i++)
	    {
	        for(int j=i-1;j>=0;j--)
	        {
	            if(arr[j]<arr[i])
	            {
	                int possibleAns=dp[j]+arr[i];
	                dp[i]=max(dp[i],possibleAns);
	            }
	        }
	    }
	    int ans=dp[0];
	    for(int i=1;i<n;i++)
	    {
	        ans=max(ans,dp[i]);
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends