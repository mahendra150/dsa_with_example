class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixSum=0;
        
        unordered_map<int,int>h;
        h[0]=(-1);
        
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int rem=prefixSum%k;
            
            if(rem<0)rem+=k;
            
            if(h.count(rem)){
                if(i-h[rem]>=2)return true;
            }
            else{
                h[rem]=i;
            }
        }
        
        return false;
        
    }
};