class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        
        priority_queue<int>q(stones.begin(),stones.end());
        
        while(q.size()>1){
            int y=q.top();
            q.pop();
            int x=q.top();
            q.pop();
            if(y==x and q.empty())return 0;
            if(y==x)continue;
            else q.push(y-x);
        }
        
        int ans=q.top();
        return ans;
        
    }
};