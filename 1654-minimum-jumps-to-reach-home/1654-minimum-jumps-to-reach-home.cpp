class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> notAllowed(forbidden.begin(),forbidden.end());
        
        vector<vector<int>> visited(2,vector<int>(1e5));
        // visited[0][forward]  and  visited[1][backward]
        queue<pair<int,bool>> q;
        
        q.push({0,false});
        visited[0][0]=1;
        visited[1][0]=1;
            
        int jumps=0;
        
        while(!q.empty()){
            int k=q.size();
            
            while(k--){
                
                auto node= q.front();
                q.pop();
                auto pos= node.first;
                auto check= node.second;
                if(pos==x)return jumps;
                int forward= pos+a;
                auto backward= pos-b;
                
            if(forward<1e5 and visited[0][forward]==0 and !notAllowed.count(forward)){
                    q.push({forward,false});
                    visited[0][forward]=1;
                }
            if(backward>=0 and visited[1][backward]==0 and !notAllowed.count(backward) and !check){
                    q.push({backward,true});
                    visited[1][backward]=1;
                }
                
            }
            
            jumps+=1;
        }
        
        return (-1);
        
    }
};