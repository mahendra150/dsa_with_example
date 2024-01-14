class Solution {
public:
    
    bool combinationSum(vector<int>& nums,int target,int i,vector<bool>&visited,int k,int targetSum)
    {
        //base case
        if(k==1)return true;
         if(i>=nums.size()) //This line is important to avoid tle
           return false;
        if(target==targetSum)return combinationSum(nums,0,0,visited,k-1,targetSum);
        //recursive case
        for(int j=i;j<nums.size();j++)
        {
            int candidate=nums[j];
            if( !visited[j] and target+candidate<=targetSum)
            {
                visited[j]=true;
                bool ans=combinationSum(nums,target+candidate,j+1,visited,k,targetSum);
                if(ans)return true;
                visited[j]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int range=0;
        for(int i=0;i<n;i++)range+=nums[i];
        if(range%k != 0 or nums.size()<k)return false;
        int targetSum=(range/k);
        sort(begin(nums),end(nums),greater<int>());// For avoid extra calculation
        
        vector<bool>visited(n,false);
        int i=0;
        int target=0;
       return combinationSum(nums,target,i,visited,k,targetSum);
        
    }
};