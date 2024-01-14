static bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(),points.end(),comp);
        int n=points.size();
        int i=0;
        int arrows=1;
        for(int j=1;j<n;j++){
            if(points[j][0]>points[i][1]){
                arrows++;
                i=j;
            }
        }
        return arrows;
        
    }
};