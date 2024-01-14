class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> freq;
        
        for(int i=0;i<n;i++){
            
            freq[nums[i]]+=1;
        }
        
        int dom=(-1);
        for(auto i:freq){
            
            if(i.second>(n/2)){
                
                dom=i.first;
                break;
            }
        }
        
        int left=0;
        int right;
        for(int i=0;i<n-1;i++){
            
            if(nums[i]==dom)left+=1;
            right= freq[dom]-left;
            
            if(left*2>(i+1) and right*2>(n-i-1)){
                
                return (i);
            }
        }
        
        return (-1);
    }
};