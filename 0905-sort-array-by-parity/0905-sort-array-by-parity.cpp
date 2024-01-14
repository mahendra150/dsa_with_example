class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();
        int indx=0;
        
        unordered_set<int> taken;
        
        vector<int> res;
        for(int i=0;i<n;i++){
            
            if(nums[i]&1){
                
                res.push_back(nums[i]);
                taken.insert(nums[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(!taken.count(nums[i]))res.push_back(nums[i]);
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};