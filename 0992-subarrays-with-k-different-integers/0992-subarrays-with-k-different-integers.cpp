class Solution {
public:
    int subarraysWithAtMostKDistinct(vector<int> &nums,int k){
        int n=nums.size();
        
        unordered_map<int,int>freq;
        unordered_set<int>st;
        int left=0,right=0;
        
        int res=0;
        while(right<n){
            
            if(freq[nums[right]]==0)st.insert(nums[right]);
            freq[nums[right]]+=1;
            
            while(st.size()>k){
                
                freq[nums[left]]-=1;
                if(freq[nums[left]]==0)st.erase(st.find(nums[left]));
                left++;
            }
            
            res+=(right-left+1);
            right++;
        }
        
        return res;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return subarraysWithAtMostKDistinct(nums,k)-subarraysWithAtMostKDistinct(nums,k-1);
    }
};