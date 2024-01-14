class Solution {
public:
    int utility(vector<int>&nums,int target)
    {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(nums[m]<=target)
            {
               s=m+1; 
            }
            else e=m-1;
        }
        return s;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //Binary Search Approach-->Almost same as Matrix Median
        
        int n=matrix.size();
        int s=matrix[0][0];
        int e=matrix[n-1][n-1];
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int count=0;
            for(int i=0;i<n;i++)
            {
                count+=utility(matrix[i],mid);
            }
            if(count<k)s=mid+1;
            else if(count>=k)
            {
                int res=mid;
                e=mid-1;
            }
        }
        return s;
        
    }
};