class Solution {
public:
    bool isPossible(vector<int> &nums,int required,int k,int mid){
        int n= nums.size();
        
        int streak=0;
        int count=0;
        for(int i=0;i<n;i++){
            
            if(nums[i]<=mid)count+=1;
            else count=0;
            
            if(count==k){
                
                streak+=1;
                count=0;
            }
            
            if(streak>= required)return true;
        }
        
        
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        
        long long val= m*1ll*k*1ll;
        if(val>n)return (-1);
        
        int start= INT_MAX;
        int end=INT_MIN;
        for(int i=0;i<n;i++){
            
            start=min(start,bloomDay[i]);
            end=max(end,bloomDay[i]);
        }
        
        int res;
        while(start<=end){
            
            int mid= start + (end-start)/2;
            
            if(isPossible(bloomDay,m,k,mid)){
                
                res=mid;
                end=mid-1;
            }
            else start= mid+1;
        }
        
        return start;
        
    }
};