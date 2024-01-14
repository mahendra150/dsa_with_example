class NumArray {
public:
    int prefixSum[10005];
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }
        
        
    }
    
    int sumRange(int left, int right) {
        return left<=0?prefixSum[right]:prefixSum[right]-prefixSum[left-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */