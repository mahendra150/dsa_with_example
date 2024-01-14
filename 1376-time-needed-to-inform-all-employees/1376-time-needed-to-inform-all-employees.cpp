class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int,vector<int>> h;
        for(int i=0;i<n;i++){
            
            h[manager[i]].push_back(i);
        }
        
        int ans= 0;
        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});
        
       while(!q.empty()){
           
           auto node= q.front();
           q.pop();
           auto manager= node.first;
           auto currentTime= node.second;
           ans= max(ans, currentTime);
           
           for(auto subordinate: h[manager]){
               
               q.push({subordinate,currentTime+ informTime[subordinate]});
           }
       }
        
        
        return ans;
        
    }
};