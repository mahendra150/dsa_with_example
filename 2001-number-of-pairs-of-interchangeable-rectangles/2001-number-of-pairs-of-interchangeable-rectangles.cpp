class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long int n= rectangles.size();
        unordered_map<double,long long> h;
        
        long long int count=0;
        for(int i=0;i<n;i++){
            
            auto x= rectangles[i][0];
            auto y= rectangles[i][1];
            
            double ratio= (double)x/y;
            if(h.count(ratio))count+= h[ratio];
            
            h[ratio]+=1;
        }
        
       
        
        return count;
        
    }
};