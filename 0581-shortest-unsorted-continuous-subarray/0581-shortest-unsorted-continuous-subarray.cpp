class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        
        int left=0,right=n-1;
        
        //Finding the Window --> finding  [left   right]
        
       while(left<n-1){
           if(nums[left]>nums[left+1])break;
           
           left++;
       }
        
        while(right>0){
            if(nums[right]<nums[right-1])break;
            
            right--;
        }
        
        if (left == nums.size()-1) return 0;
        
        //mi-> minimum valur of the window
        //max->maximum value of the window
        int mi=INT_MAX;
        int mx=INT_MIN;
        
        for(int i=left;i<=right;i++){
            mi=min(mi,nums[i]);
            mx=max(mx,nums[i]);
        }
        
        //Now we would slide the window to both the sides, dynamic sliding window  <--[left right]-->
        //We would first check if (left and right) of the window are sorted or not
        
        while(left>0 and nums[left-1]>mi)left--;
        
        while(right<n-1 and nums[right+1]<mx)right++;
        
        return (right-left+1);
        
    }
};