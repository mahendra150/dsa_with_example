class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n= nums.size();
        
        unordered_map<int,int> h;
        for(int i=0;i<n;i++){
            
            if(h.count(nums[i])){
                
                if(i-h[nums[i]]<=k)return true;
            }
            
            h[nums[i]]= i;
        }
        
        return false;
    }
};