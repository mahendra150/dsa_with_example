class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        
        int totalSum=0;
        int currSum=0;
        int minSum=0;
        
        for(int i=0;i<n;i++){
            
            totalSum+=cardPoints[i];
            currSum+= cardPoints[i];
            if(i>=n-k){
                currSum-=cardPoints[i-(n-k)];
                minSum=min(minSum,currSum);
            }
            else minSum+=cardPoints[i];
        }
        
        //     maximum sum from (left) and (right) edges
        return totalSum-minSum;
        
    }
};