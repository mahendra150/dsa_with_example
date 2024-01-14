class Solution {
public:
    void utility(int i,int target,int n,int k,vector<int>&curr_ans,vector<vector<int>>&ans)
    {
        //base case
        if(k==0 and target==0)
        {
            ans.push_back(curr_ans);
            return;
        }
        //recursive case
        for(int j=i;j<=9;j++)
        {
            if(target-j>=0 and k)
            {
                curr_ans.push_back(j);
                utility(j+1,target-j,n,k-1,curr_ans,ans);
                curr_ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int target=n;
        int i=1;
        vector<int>curr_ans;
        vector<vector<int>>ans;
        utility(i,target,n,k,curr_ans,ans);
        return ans;
        
        
    }
};