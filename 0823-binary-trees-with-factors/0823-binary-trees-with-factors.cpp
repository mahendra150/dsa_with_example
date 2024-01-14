class Solution {
public:
    int mod= 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        // int n= arr.size();
        
        set<int> st(arr.begin(),arr.end());
        unordered_map<int,int> dp;
        
        sort(arr.begin(),arr.end());
        for(auto num:arr)dp[num]=1;
        
        
        for(auto n: arr){
    
            for(auto i: arr){
                st.insert(i);
                
                if(i>sqrt(n))break;
                
                if(n % i==0 and st.find(n/i) != st.end()){
                    
                    long long possibleAns= (long long)dp[i]*dp[n/i];
                    
                    if(i==n/i)dp[n]= (dp[n] + possibleAns)%mod;
                    
                    else dp[n]= (dp[n] + possibleAns*2)%mod;
                }
            }
        }
        
        int res=0;
        for(auto val: dp){
            
            res= (res +  val.second)%mod;
        }
        
        return res;
    }
};