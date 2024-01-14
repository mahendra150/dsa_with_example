class Solution {
public:
    bool isPossible(int required,vector<int> &nums,int k){
        int n=nums.size();
        int count=1;
        int sum=0;
        
        for(int i=0;i<n;i++){
             if(nums[i]>required)return false;
            if(sum+nums[i]<=required)sum+=nums[i];
            else{
                sum=0;
                sum+=nums[i];
                count++;
            }
        }
        
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        int start=nums[0];
        int end=0;
        
        for(int i=0;i<n;i++){
            start=max(start,nums[i]);
            end+=nums[i];
        }
        int res=0;
        
        while(start<=end){
            int mid=start + (end-start)/2;
            
            if(isPossible(mid,nums,k)){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        
        return res;
        
    }
};