class Solution {
public:
    double findDistance(vector<int> &p1,vector<int> &p2){
        double dist= (double) sqrt((p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]));
        
        return dist;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<vector<int>> nums= {p1,p2,p3,p4};
        int n=nums.size();
        set<double> s;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                auto p1=nums[i];
                auto p2=nums[j];
                double distance= findDistance(p1,p2);
                if(distance != 0){
                    s.insert(distance);
                }
                else return false;
            }
        }
        
        return s.size() == 2;
        
    }
};