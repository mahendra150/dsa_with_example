class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        
        map<int,int>h;
        
        for(int i=0;i<n;i++){
            
            h[intervals[i][0]]=i;
        }
        
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            
            auto address= h.lower_bound(intervals[i][1]);
            if(address != h.end()){
                ans[i]=address->second;
            }
            
            else ans[i]=(-1);
        }
        
        return ans;
        
    }
};