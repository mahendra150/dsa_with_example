class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map<int,int>h;
        h[0]=1;
        
        int res=0;
        int curr=0;
        for(int i=0;i<n;i++){
            
            curr+= nums[i]%2;
            if(h.count(curr-k))res+=h[curr-k];
            
            h[curr]++;
        }
        
        return res;
        
    }
};