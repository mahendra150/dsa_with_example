class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n= nums.size();
        
        unordered_map<long long,long long> freq;
        multiset<long long> st;
        long long maxSum= 0;
        
        long long sum=0;
        for(long long i=0;i<k and i<n;i++){
            
            freq[nums[i]]+=1;
            st.insert(nums[i]);
            sum+= nums[i];
        }
        
        if(st.size()==freq.size())maxSum=max(maxSum,sum);
        
        for(long long i=k;i<n;i++){
            
            freq[nums[i]]+=1;
            freq[nums[i-k]]-=1;
            if(!freq[nums[i-k]])freq.erase(nums[i-k]);
            
            st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            
            sum-= nums[i-k];
            sum+= nums[i];
            
            if(st.size()==freq.size())maxSum=max(maxSum,sum);
        }
        
        return maxSum;
        
    }
};