// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void utility(vector<int> arr,int i,int N,int sum,vector<int>&ans)
    {
        //--->base case
        if(i==N)
        {
            ans.push_back(sum);
            return;
        }
        
        //--->recursive case
        
        //Inclusion Step
        utility(arr,i+1,N,sum,ans);
        
        //Exclusion Step
         utility(arr,i+1,N,sum+arr[i],ans);
       
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        int sum=0;
        int i=0;
        utility(arr,i,N,sum,ans);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends