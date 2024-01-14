// typedef pair<int,int> node;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        
        deque<pair<long long,long long>> dq;
        long long sum=0;
        long long minLen= INT_MAX;
        
        for(long long i=0;i<n;i++){
            
            sum+=nums[i];
            
            if(sum>=k)minLen=min(minLen,i+1);
            
            //if(B >= target)    ==>    if(C-A >= target)
            
            pair<long long,long long> curr= {INT_MIN,INT_MIN};
            while( !dq.empty() and sum-dq.front().second>=k){
                
                curr=dq.front();
                dq.pop_front();
            }
            
            if(curr.second != INT_MIN){
                
                minLen=min(minLen,(i-curr.first));
            }
            
            while(!dq.empty() and sum<=dq.back().second){
                dq.pop_back();
            }
            
            dq.push_back({i,sum});
        }
        
       return (minLen==INT_MAX)?(-1):minLen;
    }
};