class Solution {
public:
    bool isPossible(int required,vector<int> &weights,int days){
        int n=weights.size();
        
        int count=1;
        int sum=0;
        
        for(int i=0;i<n;i++){
            
            if(weights[i]>required)return false;
            
            if(sum+weights[i]<=required){
                sum+=weights[i];
            }
            else{
                count++;
                sum=0;
                sum+=weights[i];
            }
        }
        
        if(count<=days)return true;
        
        return false;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        
        int start=weights[0];
        int end=0;
        
        for(int i=0;i<n;i++){
            
            start=max(start,weights[i]);
            end+=weights[i];
        }
        
        int res;
        while(start<=end){
            
            int mid= start + (end-start)/2;
            
            if(isPossible(mid,weights,days)){
                
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        
        return start;
        
    }
};