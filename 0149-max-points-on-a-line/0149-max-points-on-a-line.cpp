class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n= points.size();
        
        int ans= 0;
        
        for(auto it1:points){
            unordered_map<double,int> h;
            for(auto it2:points){
                if(it1==it2)continue;
                
                double x1= it1[0];
                double x2= it2[0];
                double y1= it1[1];
                double y2= it2[1];
                
                double slope;
                if(x2-x1==0)slope=INT_MAX;
                else{
                    slope= (y2-y1)/(x2-x1);
                }
                    h[slope]++;
                    ans=max(ans, h[slope]);
            }
        }
        
        return ans+1;
        
    }
};