class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        
        int curr=0;
        int total=0;
        
        for(int i=2;i<n;i++){
            
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                curr++;
                total=total+curr;
            }
            else curr=0;
        }
        
        return total;
        
    }
};