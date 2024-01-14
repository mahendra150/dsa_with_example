class Solution {
public:
    void merge(int start,int mid,int end,vector<int> &nums){
        
        int i= start;
        int j=mid+1;
        
        vector<int> sorted(end-start+1);
        int k=0;
        while(i<=mid and j<=end){
            
            if(nums[i]<nums[j])sorted[k++]=nums[i++];
            else sorted[k++]= nums[j++];
        }
        
        while(j<=end)sorted[k++]= nums[j++];
        
        while(i<=mid)sorted[k++]= nums[i++];
        
        k=0;
        for(i=start;i<=end;i++){
            
            nums[i]= sorted[k++];
        }
        
        
    }
    void mergeSort(int start,int end,vector<int> &nums){
        
        //base case
        
        if(start>=end)return;
        //recursive case
        
        int mid= (start + end)/2;
        
        mergeSort(start,mid,nums);
        mergeSort(mid+1,end,nums);
        
        merge(start,mid,end,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n= nums.size();
        
        mergeSort(0,n-1,nums);
        return nums;
    }
};