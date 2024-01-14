typedef pair<int,int>node;
class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size();
        priority_queue<node,vector<node>,greater<node>>pq;
        unordered_map<int,int>h;
        vector<int> Q=queries,ans;
        int i=0;
        
        sort(intervals.begin(),intervals.end(),comp);
        sort(Q.begin(),Q.end());
        
        for(auto q:Q){
            
            while(i<n and q>=intervals[i][0]){
                int l=intervals[i][0],r=intervals[i][1];
                pq.push({r-l+1,r});
                i++;
            }
            
            while(!pq.empty() and q>pq.top().second)
                pq.pop();
            
            h[q]= pq.empty()?(-1):pq.top().first;
            
            
        }
        
        for(int i=0;i<queries.size();i++){
            ans.push_back(h[queries[i]]);
        }
        
        return ans;
        
    }
};