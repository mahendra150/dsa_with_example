class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        
        while(l<=r){
            while(l<r and nums[l]==nums[l+1])l++;
            
            while(l<r and nums[r]==nums[r-1])r--;
            
            int mid=r + (l-r)/2;
            
            if(nums[mid]==target)return true;
            else if(nums[l]<=nums[mid]){
                if(target>=nums[l] and target<=nums[mid])r=mid-1;
                else l=mid+1;
            }
            else if(nums[mid]<=nums[r]){
                if(target>=nums[mid] and target<=nums[r]){
                    l=mid+1;
                }
                else r=mid-1;
            }
        }
        
        return false;
        
    }
};