class Solution {
public:
    void merge(int start,int mid,int end,vector<int> &res,vector<pair<int,int>> &nums){
        int i=start;
        int j=mid+1;
        int k=0;
        vector<pair<int,int>> sortedNums(end-start+1);
        
        while(i<=mid and j<=end){
            if(nums[i].first>nums[j].first){
                res[nums[i].second]+=(end-j+1);
                sortedNums[k++]=nums[i++];
            }
            else {
                sortedNums[k++]=nums[j++];
            }
        }
        
        while(i<=mid){
            sortedNums[k++]=nums[i++];
        }
        
        while(j<=end){
            sortedNums[k++]=nums[j++];
        }
        
        k=0;
        i=start;
        
        while(i<=end){
            nums[i++]=sortedNums[k++];
        }
    }
    void mergeSort(int start,int end,vector<int> &res,vector<pair<int,int>> &nums){
        //base case
        if(start>=end)return;
        
        //recursive case
        
        int mid=start + (end-start)/2;
        
        mergeSort(start,mid,res,nums);
        mergeSort(mid+1,end,res,nums);
        
        merge(start,mid,end,res,nums);
        
        
    }
    vector<int> countSmaller(vector<int>& nums) {
        int  n=nums.size();
        
        vector<int>res(n,0);
        int start=0,end=n-1;
        vector<pair<int,int>>preComputation;
        
        for(int i=0;i<n;i++)preComputation.push_back({nums[i],i});
        
        mergeSort(start,end,res,preComputation);
        
        return res;
        
        
    }
};