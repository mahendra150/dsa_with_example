class Solution {
public:
    vector<vector<vector<int>>> dp;
    int dfs(string number,int pos=0,int tight=1,int mask=0){
        
        //base case
        
        if(pos==number.length()){
            
            return dp[pos][tight][mask]= mask != 0;
        }
        //recursive case
        
        if(dp[pos][tight][mask] != (-1))return dp[pos][tight][mask];
        int ans=0;
        
        
        if(tight==1){
            
            //tight case
            
            int limit= number[pos]-48;
            for(int i=0;i<=limit;i++){
                
                if(mask & (1<<i)) continue;
                
                int newMask= (mask==0 and i==0)?mask: mask | (1<<i);
                
                if(i==limit){
                    
                    // for next (pos) --> tight case
                    ans+= dfs(number,pos+1,1,newMask);
                }
                else{
                    
                    // for next (pos) --> non-tight state
                    ans+= dfs(number,pos+1,0,newMask);
                }
            }
            
        }
        else{
            
            //non-tight case
            
            for(int i=0;i<=9;i++){
                
                if(mask & (1<<i))continue;
                
                int newMask= (mask==0 and i==0)?mask: mask | (1<<i);
                
                
                ans+= dfs(number,pos+1,0,newMask);
            }
        }
        
        return dp[pos][tight][mask]= ans;
        
        
    }
    int countSpecialNumbers(int n) {
        
        string number= to_string(n);
        
        dp.resize(11,vector<vector<int>>(2,vector<int>(1024,-1)));
        return dfs(number);
    }
};