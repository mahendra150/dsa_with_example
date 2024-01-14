// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool utility(int i,int k,int *a,int range,int targetSum,vector<bool>&visited,int n)
  {
      //base case
      if(k==1)return true;
      if(targetSum==range)return utility(0,k-1,a,range,0,visited,n);
      //recursive case
      
      for(int j=i;j<n;j++)
      {
          int candidate=a[j];
          if(!visited[j] and targetSum+candidate<=range)
          {
              visited[j]=true;
              if(utility(j+1,k,a,range,targetSum+candidate,visited,n))return true;
              visited[j]=false;
          }
      }
      return false;
  }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int range=0;
         for(int i=0;i<n;i++)range+=a[i];
         if(range%k!=0 or n<k)return false;
         range=range/k;
         int i=0,targetSum=0;
         vector<bool>visited(n,false);
         return utility(i,k,a,range,targetSum,visited,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends