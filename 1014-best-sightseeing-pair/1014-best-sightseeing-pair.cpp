class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size();
        vector<int> nums= values;
        
        int maxVal= nums[0]+0;
        int profit= INT_MIN;
        
        for(int j=1;j<n;j++){
            
            profit=max(profit,maxVal + nums[j]-j);
            
            maxVal=max(maxVal,nums[j]+j);
        }
        
        return profit;
    }
};