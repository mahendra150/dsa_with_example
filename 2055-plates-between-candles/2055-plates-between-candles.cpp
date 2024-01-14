class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.length();
        
        vector<int> prev(n,n), next(n,n), prefixSum(n,0);
        
        if(s[0]=='|'){
            prev[0]=0;
        }
        else{
            prefixSum[0]=1;
        }
        
        for(int i=1;i<n;i++){
            
            if(s[i]=='|'){
                prev[i]=i;
                prefixSum[i]=prefixSum[i-1];
            }
            else{
                prev[i]=prev[i-1];
                prefixSum[i]= 1+prefixSum[i-1];
            }
        }
        
        if(s[n-1]=='|'){
            next[n-1]=n-1;
        }
        for(int i=n-2;i>=0;i--){
            
            if(s[i]=='|'){
                next[i]=i;
            }
            else{
                next[i]=next[i+1];
            }
        }
        
        vector<int> res;
        for(auto q:queries){
            
            auto left=q[0];
            auto right=q[1];
            
            auto i=next[left];
            auto j=prev[right];
            
            if(j<=i or j==n or i==n)res.push_back(0);
            else res.push_back(prefixSum[j]-prefixSum[i]);
        }
        
        return res;
        
    }
};