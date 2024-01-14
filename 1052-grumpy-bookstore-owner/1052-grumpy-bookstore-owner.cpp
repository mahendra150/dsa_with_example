class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int satisfiedCustomers=0;
        
        //Finding baseline number of satisfied customers
        for(int i=0;i<n;i++){
            
            if(grumpy[i]==0)satisfiedCustomers+=customers[i];
        }
        
        int left=0;
        int right=0;
        int windowMaxNumOfUnsatisfied=0;
        int currSum=0;
        
        //Finding window (X) which has max number of unsatisfied customers
        while(right<n){
            
            if(grumpy[right]==1)currSum+=customers[right];
            
            //Window (X)
            if(right-left+1>=minutes){
                
                windowMaxNumOfUnsatisfied=max(windowMaxNumOfUnsatisfied,currSum);
                if(grumpy[left]==1)currSum-=customers[left];
                left++;
            }
            
            right++;
        }
        
        return satisfiedCustomers + windowMaxNumOfUnsatisfied;
        
    }
};