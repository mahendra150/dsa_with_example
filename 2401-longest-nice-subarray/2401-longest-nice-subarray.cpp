class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n= nums.size();
        
        int maxLen=0;
        int left=0,right=0;
        
        int window=0;
        while(right<n){
            
            while((window & nums[right]) != 0){
                
                window&= ~(nums[left]);
                left++;
            }
            
            maxLen=max(maxLen,right-left+1);
            window|= nums[right];
            right++;
        }
        
        return maxLen;
    }
};