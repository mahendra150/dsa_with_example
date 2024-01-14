class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        
        unordered_map<int,int> gamesLost;
        unordered_set<int> st;
        
        for(int i=0;i<n;i++){
            
            auto winner= matches[i][0];
            auto loser= matches[i][1];
            if(!st.count(winner))st.insert(winner);
            if(!st.count(loser))st.insert(loser);
            
           gamesLost[loser]+=1;
        }
        
        vector<vector<int>> res;
        vector<int>first;
        vector<int>second;
        
        while(!st.empty()){
            
            auto val= *(st.begin());
            st.erase(st.find(val));
            
            if(gamesLost.count(val)){
                
                if(gamesLost[val]==1)second.push_back(val);
            }
            else first.push_back(val);
        }
        
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        
        res.push_back(first);
        res.push_back(second);
        
        return res;
    }
};