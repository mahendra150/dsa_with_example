class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n= nums.size();
        
        multiset<int> st;
        int k= indexDiff;
        
        
        for(int i=0;i<n;i++){
            
            if(i>k) st.erase(nums[i-k-1]);
            
            
            auto itr= st.lower_bound(nums[i] - valueDiff);
            if(itr != st.end() and *itr-nums[i] <=valueDiff)return true;
            
             st.insert(nums[i]);
        }
        
        return false;
        
    }
};