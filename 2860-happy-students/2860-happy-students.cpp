class Solution {
public:
    int countWays(vector<int>& nums) {
        int n= nums.size();
        
        int count=0;
        sort(nums.begin(),nums.end());
        if(count<nums[0])count+=1;
        
        for(int i=0;i<n;i++){
            
            int selected= i+1;
            
            if(selected> nums[i]){
                
                if(i<n-1 and selected<nums[i+1])count+=1;
                
                else if(i==n-1)count+=1;
            }
        }
        
        return count;
        
    }
};