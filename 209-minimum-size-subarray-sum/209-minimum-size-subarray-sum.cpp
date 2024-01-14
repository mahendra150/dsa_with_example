class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        
        int prefixSum=0;
        int minLen=INT_MAX;
        
        while(r<n){
            prefixSum+=nums[r];
            while(prefixSum>=target){
                minLen=min(minLen,r-l+1);
                prefixSum-=nums[l];
                l++;
            }
            r++;
        }
        return (minLen==INT_MAX?0:minLen);
    }
};