class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>res(n+1);
        
        // [first   last]  (last+1)
        
        for(auto it:bookings){
            auto first=it[0]-1;
            auto last=it[1]-1;
            auto seats=it[2];
            
            res[first]+=seats;
            res[last+1]-=seats;
        }
        
       for(int i=1;i<res.size();i++){
           res[i]+= res[i-1];
       }
        
        res.pop_back();
        return res;
        
    }
};