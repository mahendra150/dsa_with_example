class Solution {
public:
    bool isPossible(int mid,vector<int> &nums,int required){
        int n= nums.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            
            sum+= ceil((double)nums[i]/(double)mid);
        }
        
        if(sum<=required)return true;
        
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        
        int start=1,end= (int)1e9;
        
        int res=0;
        while(start<=end){
            
            int mid= start + (end-start)/2;
            
            if(isPossible(mid,nums,threshold)){
                
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        
        return res;
        
    }
};