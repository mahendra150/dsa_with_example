class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>h;
        for(int i=0;i<n;i++)
        {
            int diff=target-nums[i];
            if(h.count(diff)>0)
            {
               return {i,h[diff]}; 
            }
            else
            {
                h[nums[i]]=i;
            }
        }
        return {};
        
        
    }
};