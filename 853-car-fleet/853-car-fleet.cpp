class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        
        vector<pair<int,float>>fleet;
        
        for(int i=0;i<n;i++){
          //  float time= (target-position[i])/speed[i];
            fleet.push_back({position[i],float(target-position[i])/speed[i]});
        }
        sort(fleet.begin(),fleet.end());
        
        
        stack<float>s;
        
        for(int i=0;i<n;i++){
            float time=fleet[i].second;
            while(!s.empty() and time>=s.top()){
                s.pop();
            }
            
            s.push(time);
        }
        
        return s.size();
        
        
        
    }
};