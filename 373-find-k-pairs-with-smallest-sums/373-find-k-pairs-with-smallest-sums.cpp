class Solution {
public:
    typedef pair<int,pair<int,int>>node;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<node>q;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];;
                if(q.size()<k)
                {
                    q.push({sum,{nums1[i],nums2[j]}});
                }
                else
                {
                    node p=q.top();
                    if(sum<=p.first)
                    {
                        q.pop();
                        q.push({sum,{nums1[i],nums2[j]}});
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        
        vector<vector<int>>ans;
        while(!q.empty())
        {
            node p=q.top();
            q.pop();
            vector<int>curr_ans;
            curr_ans.push_back(p.second.first);
            curr_ans.push_back(p.second.second);
            ans.push_back(curr_ans);
            curr_ans.clear();
        }
        return ans;
        
        
    }
};