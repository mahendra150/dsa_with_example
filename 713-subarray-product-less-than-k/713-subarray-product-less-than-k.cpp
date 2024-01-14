class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        
        int n=nums.size();
        
        int left=0,right=0;
        int prefix=1;
        int count=0;
        
        while(right<n){
            prefix*=nums[right];
            
            while(prefix>=k){
                prefix/=nums[left];
                left++;
            }
                count+=(right-left+1);
            right++;
        }
        
        return count;
        
        
    }
};