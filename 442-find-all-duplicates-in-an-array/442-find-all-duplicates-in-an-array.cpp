class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int indx=abs(nums[i])-1;
            if(nums[indx]<0)ans.push_back(abs(nums[i]));
            nums[indx]=-abs(nums[indx]);
        }
        return ans;
    }
};