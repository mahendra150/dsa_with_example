class Solution {
public:
    bool isPossible(int mid,vector<int> &nums,int maxOperations){
        
        int totalOperations=0;
        
        for(auto x:nums){
            
            int numberOfOperations= (x-1)/mid;
            
            totalOperations+=numberOfOperations;
        }
        
        if(totalOperations<=maxOperations)return true;
        
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        
        int start=1;
        int end=1e9;
        int res;
        
        while(start<=end){
            
            int mid= start + (end-start)/2;
            
            if(isPossible(mid,nums,maxOperations)){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        
        return start;
        
        
    }
};