class Solution {
public:
    bool check(int i,int j,vector<int>&nums)
    {
        for(int k=i;k<j;k++)
        {
            if(nums[k]==nums[j])return false;
        }
        return true;
    }
    void utility(vector<int> nums,vector<vector<int>>&ans,int i)
    {
        //base case
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        //recursive case
        for(int j=i;j<nums.size();j++)
        {
            if((j==i or nums[j]!=nums[j-1]) and check(i,j,nums))
            {
              //  s.insert(nums[j]);
                swap(nums[i],nums[j]);
                utility(nums,ans,i+1);
                swap(nums[i],nums[j]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int i=0;
       // sort(nums.begin(),nums.end());
     //   set<int>s;
        utility(nums,ans,i);
        return ans;
        
    }
};