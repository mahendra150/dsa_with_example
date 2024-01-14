class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n= points.size();
        
        priority_queue<pair<int,int>> q;
        
        //                yi-xi          ,   xi
        q.push({points[0][1]-points[0][0],points[0][0]});
        
        int res= INT_MIN;
        for(int j=1;j<n;j++){
            
            auto xj=points[j][0];
            auto yj=points[j][1];
            
            while(!q.empty() and xj-q.top().second>k)q.pop();
            
            if(!q.empty()){
                
                auto val=q.top().first;       //yi-xi
                res=max(res,val+yj+xj);
            }
            q.push({yj-xj,xj});
        }
        
        return res;
        
    }
};