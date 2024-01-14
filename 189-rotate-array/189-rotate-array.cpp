class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>nums.size())
        {
            k=k%n;
        }
        for(int i=n;i<2*n-k;i++)
        {
            nums.push_back(nums[i%n]);
        }
        nums.erase(nums.begin(),nums.begin()+n-k);
        
    }
};