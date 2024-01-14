// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool IsValid(int A[], int N, int M, int curr){
        int sum = 0;
        int student = 1;
        for(int i = 0; i<N; i++){
            if(A[i] > curr){
                return false;
            }
            
            if(A[i]+sum > curr ){
                student++;
                sum = A[i];
            }
            else{
                sum+=A[i];
            }
            
            if(student>M){
               return false;
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if (N < M) return -1;
        int sum = 0;
        int start = A[0];
        
        for(int i = 0; i<N; i++){
            sum += A[i];
            start=min(start,A[i]);
        }
        int end = sum;
        int res = -1;
        
        while(start<=end){
            int mid = (start + end)/2;
            
            if(IsValid(A, N, M, mid) == true){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends