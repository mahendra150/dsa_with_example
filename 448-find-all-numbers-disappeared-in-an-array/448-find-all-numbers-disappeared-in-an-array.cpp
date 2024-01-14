class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int indx=abs(nums[i])-1;
            nums[indx]= -abs(nums[indx]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)ans.push_back(i+1);
        }
        return ans;
        
    }
};