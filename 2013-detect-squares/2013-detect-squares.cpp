class DetectSquares {
public:
    vector<pair<int,int>>points;
    int freq[1002][1002]={};
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        auto x=point[0];
        auto y=point[1];
        points.push_back({x,y});
        freq[x][y]++;
        
        
    }
    
    int count(vector<int> point) {
        int res=0;
        auto x1=point[0];
        auto y1=point[1];
        
        for(auto val:points){
            auto x3=val.first;
            auto y3=val.second;
            if(abs(x1-x3)!= abs(y1-y3) or abs(x1-x3)==0)continue;
            res+=freq[x3][y1]*freq[x1][y3];
        }
        
        return res;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */