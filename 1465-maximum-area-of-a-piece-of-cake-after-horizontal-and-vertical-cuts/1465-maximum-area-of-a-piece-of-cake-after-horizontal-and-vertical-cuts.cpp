class Solution {
public:
    int mod= 1e9+7;
    int utility(int length,vector<int> &nums){
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int maxDiff= nums[0];
        for(int i=1;i<n;i++){
            
            maxDiff=max(maxDiff,nums[i]-nums[i-1]);
        }
        
        maxDiff=max(maxDiff,length-nums.back());
        return maxDiff;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        long length= utility(h,horizontalCuts);
        long breadth= utility(w,verticalCuts);
        
        return (length*breadth)%mod;
    }
};