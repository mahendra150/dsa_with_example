class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for(auto& row:image){
            reverse(row.begin(),row.end());
            
            for(auto&val :row){
                val=val^1;
            }
        }
        
        return image;
        
    }
};