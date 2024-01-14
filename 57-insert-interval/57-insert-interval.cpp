static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<int>temp=newInterval;
        
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++)
        {
            if(intervals[i][0]<=temp[0])
            {
                if(temp[0]<=intervals[i][1])
                {
                    temp[0]=min(temp[0],intervals[i][0]);
                    temp[1]=max(temp[1],intervals[i][1]);
                }
                else
                {
                vector<int>curr_ans=intervals[i];
                ans.push_back(curr_ans);
                curr_ans.clear();
                }
            }
            else if(intervals[i][0]>temp[0])
            {
                if(intervals[i][0]<=temp[1])
                {
                    temp[0]=min(temp[0],intervals[i][0]);
                    temp[1]=max(temp[1],intervals[i][1]);
                }
                else
                {
                   vector<int>curr_ans=intervals[i];
                ans.push_back(curr_ans);
                curr_ans.clear(); 
                }
            }
        }
        ans.push_back(temp);
        sort(ans.begin(),ans.end(),comp);
        return ans;
        
        
    }
};