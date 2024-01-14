/* 
    Time: O(nlogn)
    Space: O(n)
    Tag: Maths, Geometry (tan inverse and radian to degree conversion), Sorting, Sliding Window
    Difficulty: H
*/
#define PI 3.14159

class Solution {
    vector<double> angles;

    int findAngles(vector<vector<int>> points, vector<int> loc) {
        int x, y;
        double angleInRad;
        int samePoints = 0;
        for (auto &v : points) {
            x = v[0] - loc[0];
            y = v[1] - loc[1];
            if (x == 0 && y == 0) {
                samePoints++;
            } else {
                angles.push_back(atan2(y, x) * 180 / PI);
                if (angles.back() < 0) angles.back() = 360 + angles.back();
            }
        }
        return samePoints;
    }

public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
        int n = points.size();
        angles.reserve(2*n);
        int res = findAngles(points, location);
        sort(angles.begin(), angles.end());
        int size=angles.size();
        for(int i=0;i<size;i++){
            angles.push_back(360+angles[i]);
        }
        
        //Sliding Window Part -->
        int left=0,right=0;
        int maxLen=0;
        while(right<angles.size()){
            
            while(angles[right]-angles[left]>angle or angles[right]-angles[left]>=360)left++;
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        
        return maxLen + res;
    }
};