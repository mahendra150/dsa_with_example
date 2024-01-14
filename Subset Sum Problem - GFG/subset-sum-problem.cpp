// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        int n=N;
        bool dp[n+1][sum+1];
	    dp[0][0]=true;
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(i==0 and j>0)dp[i][j]=false;
	           else  if(j==0)dp[i][j]=true;
	            else
	            {
	                dp[i][j]=dp[i-1][j] or (j-arr[i-1]>=0?dp[i-1][j-arr[i-1]]:false);
	            }
	        }
	    }
	    return dp[n][sum];
        /*
        int n=N;
        bool dp[n+1][sum+1];
        dp[0][0]=true;
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0 and j>0)dp[i][j]=false;
                 else if(j==0)dp[i][j]=true;
                 else
                 {
                     dp[i][j]=dp[i-1][j] or (j-arr[i-1]>=0?dp[i-1][j-arr[i-1]]:false);
                 }
                
            }
        }
        return dp[n][sum];
        */
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends