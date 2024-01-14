class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        if(!nums[0])return false;
        int jumps=0;
        int farthest=0;
        int currReach=0;
        for(int i=0;i<n-1;i++)
        {
            if(i>currReach)break;
            farthest=max(farthest,i+nums[i]);
            if(i==currReach)
            {
                jumps++;
                currReach=farthest;
            }
        }
        if(currReach>=n-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};