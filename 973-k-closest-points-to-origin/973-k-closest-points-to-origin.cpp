class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            int dist=points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(q.size()<k)
            {
                q.push({dist,{points[i][0],points[i][1]}});
            }
            else
            {
                if(dist<q.top().first)
                {
                    q.pop();
                    q.push({dist,{points[i][0],points[i][1]}});
                }
            }
        }
        vector<vector<int>>ans;
        while(!q.empty())
        {
            vector<int>curr_ans;
            pair<int,int> p=q.top().second;
            q.pop();
            curr_ans.push_back(p.first);
            curr_ans.push_back(p.second);
            ans.push_back(curr_ans);
            curr_ans.clear();
        }
        return ans;
    }
};