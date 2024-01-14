class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int currFuel=startFuel;
        int prev=0;
        int res=0;
        
        stations.push_back({target,0});
        int n=stations.size();
        priority_queue<int> q;
        
        for(auto i:stations){
            int curr= i[0];
            int gas=i[1];
            currFuel-=(curr-prev);
            
            while(!q.empty() and currFuel<0){
                currFuel+=q.top();
                q.pop();
                res+=1;
            }
            q.push(gas);
            
            if(currFuel<0)return -1;
            
            prev=curr;
        }
        
        return res;
        
        
    }
};