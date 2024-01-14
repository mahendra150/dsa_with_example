class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int s=0,e=n-1;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(mid>0 and mid<n-1 and arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])return mid;
            else if(mid<n-1 and arr[mid]<arr[mid+1])s=mid+1;
            else e=mid-1;
        }
        return -1;
        
        
        
    }
};