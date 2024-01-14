class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& w) {
        int prefixSum=0;
        
        for(int i=0;i<w.size();i++){
            prefixSum+=w[i];
            nums.push_back(prefixSum);
        }
    }
    
    int pickIndex() {
        int range=nums.back();
        
        int number=rand()%range;
        
        auto indx=upper_bound(nums.begin(),nums.end(),number);
        
        return indx-nums.begin();
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */