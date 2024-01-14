class Solution {
public:
    void utility(vector<int>&curr_ans,vector<vector<int>>&ans,vector<int>& nums,int i)
    {
       
        //recursive case
        ans.push_back(curr_ans);
        for(int j=i;j<nums.size();j++)
        {
            curr_ans.push_back(nums[j]);
            utility(curr_ans,ans,nums,j+1);
            curr_ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<vector<int>>ans;
        vector<int>curr_ans;
        utility(curr_ans,ans,nums,i);
        return ans;
        
    }
};