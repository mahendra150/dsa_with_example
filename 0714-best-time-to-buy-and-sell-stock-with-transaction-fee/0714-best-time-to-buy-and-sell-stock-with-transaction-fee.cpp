class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        // Greedy Approach --> DP State Machine
        int buy=0,sell= (-100000);
        
        for(int i=0;i<n;i++){
            
            buy=max(buy,sell+prices[i]-fee);
            
            sell=max(sell,buy-prices[i]);
        }

        return buy;
        
    }
};