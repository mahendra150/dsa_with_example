class Solution {
public:
    typedef pair<int,int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        priority_queue<p,vector<p>,greater<p>>q;
        for(auto val:freq)
        {
            if(q.size()<k)
            {
                q.push({val.second,val.first});
            }
            else
            {
                if(val.second>q.top().first)
                {
                    q.pop();
                    q.push({val.second,val.first});
                }
            }
            
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};