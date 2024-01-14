class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)freq[nums[i]]+=1;
        
        int mx=0;
        for(auto i:freq){
            
            mx=max(mx,i.second);
        }
        
        
        int left=0,right=0;
        
        int res= INT_MAX;
        unordered_map<int,int> window;
        multiset<int> st;
        bool valid= false;
        
        while(right<n){
            
            window[nums[right]]+=1;
            st.insert(window[nums[right]]);
            
            // if(window[nums[right]]==mx)valid= true;
            while(st.count(mx)){
                
                res=min(res,right-left+1);
                
                st.erase(st.find(window[nums[left]]));
                window[nums[left]]-=1;
                if(!window[nums[left]])window.erase(window.find(nums[left]));
                left++;
            }
            
            right++;
        }
        
        return res;
    }
};