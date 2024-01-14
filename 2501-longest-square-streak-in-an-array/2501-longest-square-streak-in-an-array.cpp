class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n= nums.size();
        
        unordered_set<long long int> st(nums.begin(),nums.end());
        
        int ans= 0;
        for(int i=0;i<n;i++){
            
            int len=0;
            long long  int  target= nums[i];
            
            while(st.find(target) != st.end()){
                
                len+=1;
                target=target*target;
            }
            
            ans=max(ans,len);
        }
        
        if(ans < 2)return (-1);
        
        return ans;
    }
};