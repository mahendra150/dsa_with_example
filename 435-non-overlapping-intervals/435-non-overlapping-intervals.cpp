static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count=0;
        int n=intervals.size();
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(intervals[i][1]<=intervals[j][0])i=j;
            else count++;
        }
        return count;
        
    }
};