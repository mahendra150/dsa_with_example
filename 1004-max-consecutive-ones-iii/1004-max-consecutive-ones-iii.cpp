class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        
        int i=0,j=0;
        int zero_count=0;
        int maxLen=0;
        
        while(i<n){
            if(nums[i]==0)zero_count++;
            
            while(zero_count>k){
                if(nums[j]==0)zero_count--;
                j++;
            }
            
            maxLen=max(maxLen,i-j+1);
            i++;
        }
        
        return maxLen;
    }
};