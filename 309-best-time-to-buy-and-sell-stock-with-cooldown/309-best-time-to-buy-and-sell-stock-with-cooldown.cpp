class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Dp State Machine Approach
        
        int n=prices.size();
        int noStock[n];
        int inHand[n];
        int sold[n];
        
        noStock[0]=0;
        sold[0]=0;
        inHand[0]=(-prices[0]);
        
        for(int i=1;i<n;i++)
        {
            noStock[i]=max(noStock[i-1],sold[i-1]);
            inHand[i]=max(inHand[i-1],noStock[i-1]-prices[i]);
            sold[i]=inHand[i-1]+prices[i];
        }
        
        return max(noStock[n-1],sold[n-1]);
        
    }
};