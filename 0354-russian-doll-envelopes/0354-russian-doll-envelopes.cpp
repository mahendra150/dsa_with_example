class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        
        if(a[0]==b[0])return a[1]>b[1];
        
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n= envelopes.size();
        
        vector<int> dp;
        
        sort(envelopes.begin(),envelopes.end(),comp);
        
        for(int i=0;i<n;i++){
            
            auto width= envelopes[i][0];
            auto height= envelopes[i][1];
            
            auto indx= lower_bound(dp.begin(),dp.end(),height) - dp.begin();
            if(indx>=dp.size()){
                
                dp.push_back(height);
            }
            else{
                
                dp[indx]= height;
            }
            
        }
        
        return dp.size();
    }
};