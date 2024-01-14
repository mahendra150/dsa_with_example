class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int i,vector<int> &nums,vector<int> &currAns){
        int n= nums.size();
        //base case
        
        if(currAns.size()>=2)ans.push_back(currAns);
        //recursive case
        
        unordered_map<int,bool> visited;
        for(int j=i;j<n;j++){
            
            if((currAns.empty() or nums[j]>=currAns.back()) and !visited[nums[j]]){
                
                visited[nums[j]]= true;
                currAns.push_back(nums[j]);
                dfs(j+1,nums,currAns);
                currAns.pop_back();
            }
        }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> currAns;
        dfs(0,nums,currAns);
        
        return ans;
    }
};