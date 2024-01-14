class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> dp(n,1);
        vector<int> pre(n,-1);
        
        sort(nums.begin(),nums.end());
        int maxLen=0;
        int indx= (-1);
        
        for(int i=0;i<n;i++){
            
            for(int j=i-1;j>=0;j--){
                
                if(nums[i] % nums[j] == 0){
                    
                    int possibleAns= dp[j]+1;
                    if(possibleAns>dp[i]){
                        
                        dp[i]= possibleAns;
                        pre[i]= j;
                    }
                }
            }
            
            if(dp[i]>maxLen){
                
                maxLen= dp[i];
                indx= i;
            }
        }
        
        vector<int> res;
        while(indx != (-1)){
            
            res.push_back(nums[indx]);
            indx= pre[indx];
        }
        
        return res;
    }
};