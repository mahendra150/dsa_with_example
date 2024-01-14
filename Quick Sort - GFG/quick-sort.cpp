// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void sort(int s,int e,int *arr)
    {
        if(s>=e)return;
        
        int mid=partition(arr,s,e);
        
        sort(s,mid-1,arr);
        sort(mid+1,e,arr);
    }
    void quickSort(int arr[], int low, int high)
    {
        // code here
        sort(low,high,arr);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int s=low,e=high;
       int i=s-1,j=s;
       int pivot=arr[e];
       while(j<e)
       {
          if(arr[j]<pivot)
          {
              i++;
              swap(arr[i],arr[j]);
          }
          j++;
       }
       swap(arr[i+1],arr[e]);
       return i+1;
    }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends