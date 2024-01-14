class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
       int left[100005];
        int right[100005];
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++)left[i]=left[i-1]*nums[i];
        for(int i=n-2;i>=0;i--)right[i]=right[i+1]*nums[i];
            
            vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int possibleAns=(i==0?1:left[i-1])*(i==n-1?1:right[i+1]);
            ans.push_back(possibleAns);
        }
        return ans;
        
    }
};