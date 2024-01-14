class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n= nums.size();
        
        unordered_map<int,int> h;
        int count=0;
        
        for(int i=0;i<n;i++)h[nums[i]]+=1;
        
        if(k){
            
            for(auto i:h){
                
                if(h.count(i.first+k))count+=1;
            }
        }
        else{
            
            for(auto i:h){
                
                if(i.second>1)count+=1;
            }
        }
        
        return count;
       
    }
};