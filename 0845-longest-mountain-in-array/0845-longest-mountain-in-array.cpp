class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        vector<int> nums= arr;
        int n= nums.size();
        
        int maxLen=0;
        for(int i=1;i<n-1;i++){
            
            if(nums[i]>nums[i-1] and nums[i]>nums[i+1]){
                
                int left= i-1;
                int right= i+1;
                
                while(left>0 and nums[left]>nums[left-1])left--;
                
                while(right<n-1 and nums[right]>nums[right+1])right++;
                
                maxLen=max(maxLen,right-left+1);
            }
        }
        
        return maxLen;
    }
};