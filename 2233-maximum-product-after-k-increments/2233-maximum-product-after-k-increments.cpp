class Solution {
public:
    int mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        
        long long int res=1;
//         for(int i=0;i<n;i++){
            
//             res*=nums[i];
//         }
        
        priority_queue<int,vector<int>,greater<int>> q(nums.begin(),nums.end());
        while(k--){
            
            auto val=q.top();
            q.pop();
            val+=1;
            q.push(val);
        }
        
        while(!q.empty()){
            
            res=(res*q.top())%mod;
            q.pop();
        }
        
        return res%mod;
    }
};