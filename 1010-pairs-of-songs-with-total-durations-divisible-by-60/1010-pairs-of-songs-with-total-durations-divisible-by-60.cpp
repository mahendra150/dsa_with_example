class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n= time.size();
        
        unordered_map<int,int> h;
        int count=0;
        for(int i=0;i<n;i++){
            
            int rem= time[i]%60;
            if(rem==0)count+=h[0];
            else count+=h[60-rem];
            h[rem]+=1;
        }
        
        return count;
        
    }
};