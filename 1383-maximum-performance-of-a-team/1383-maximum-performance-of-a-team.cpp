class Solution {
public:
    int mod= 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> nums;
        
        for(int i=0;i<n;i++){
            
            nums.push_back({efficiency[i],speed[i]});
        }
        
        sort(nums.rbegin(),nums.rend());
        priority_queue<int,vector<int>,greater<int>> q;
        
        long long totalSpeed=0;
        long long res=0;
        for(int i=0;i<n;i++){
            
            auto currEfficiency= nums[i][0];
            auto currSpeed= nums[i][1];
            
            totalSpeed+= currSpeed;
            
            q.push(currSpeed);
            if(q.size()>k){
                
                totalSpeed-= q.top();
                q.pop();
            }
                
                res=max(res,totalSpeed*currEfficiency);
        }
        
        return res%mod;
        
    }
};