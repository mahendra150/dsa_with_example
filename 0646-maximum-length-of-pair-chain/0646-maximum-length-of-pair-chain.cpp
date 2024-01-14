class Solution {
public:
    vector<int> dp;
    
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]<b[1];
        
        return a[0]<b[0];
    }
    
    int customUpperBound(int indx,vector<vector<int>> &pairs){
        int n= pairs.size();
        
        int start= indx+1;
        int end= n-1;
        int res= (-1);
        
        while(start<=end){
            
            int mid= start + (end-start)/2;
            
            if(pairs[mid][0]<=pairs[indx][1])start= mid+1;
            else{
                
                res= mid;
                end= mid-1;
            }
        }
        
        return res;
    }
    int dfs(int indx,vector<vector<int>> &pairs){
        
        //base case
        
        if(indx>=pairs.size())return dp[indx]= 0;
        //recursive case
        if(dp[indx] != (-1))return dp[indx];
        
        int nextIntervalIndx= customUpperBound(indx,pairs);
        
        // Principle of Inclusion and Exclusion
        
        // Exclusion Step
        
        int ans;
        
        int exclude= 0 + dfs(indx+1,pairs);
        
        int include= 1 + (nextIntervalIndx==(-1)?0:dfs(nextIntervalIndx,pairs));
        
        ans=max(include,exclude);
        
        cout<<indx<<"-->"<<include<<"-->"<<exclude<<endl;
        
        return dp[indx]= ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n= pairs.size();
        
        sort(pairs.begin(),pairs.end(),comp);
        
        dp.resize(n+1,-1);
        return dfs(0,pairs);
        
    }
};