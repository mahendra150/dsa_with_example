class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int ma=ans;
        int mi=ans;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)swap(ma,mi);
            
            ma=max(ma*nums[i],nums[i]);
            mi=min(mi*nums[i],nums[i]);
            ans=max(ans,ma);
        }
        return ans;
    }
};