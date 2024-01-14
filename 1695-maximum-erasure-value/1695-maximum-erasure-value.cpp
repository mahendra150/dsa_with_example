class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        
        int left=0,right=0;
        int res=0,sum=0;
        unordered_set<int>st;
        
        while(right<n){
            
            while(st.find(nums[right]) != st.end()){
                sum-=nums[left];
                st.erase(st.find(nums[left]));
                left++;
            }
            
            sum+=nums[right];
            res=max(res,sum);
            st.insert(nums[right]);
            right++;
            
        }
        
        return res;
        
    }
};