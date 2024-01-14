




class Solution {
public:
    void transformPoints(vector<vector<int>> &buildings,vector<pair<int,int>> &points){
       int n=buildings.size();
        
        for(int i=0;i<n;i++){
           points.push_back(make_pair(buildings[i][0],-buildings[i][2]));
            points.push_back(make_pair(buildings[i][1],buildings[i][2]));
        }
        
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n=buildings.size();
        
        vector<pair<int,int>>points;
        transformPoints(buildings,points);
        
        
        sort(points.begin(),points.end());
        
        multiset<int> s= {0};
        int prevMax=0;
        vector<vector<int>>res;
        
        for(auto i:points){
            if(i.second<0){
                s.insert(-i.second);
            }
            else{
                s.erase(s.find(i.second));
            }
            
            if(*s.rbegin() != prevMax){
                vector<int>subRes;
                subRes.push_back(i.first);
                subRes.push_back(prevMax=*s.rbegin());
                res.push_back(subRes);
                subRes.clear();
            }
        }
        
        return res;
        
        
        
    }
};