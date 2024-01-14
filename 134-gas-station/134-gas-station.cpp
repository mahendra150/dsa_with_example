class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gasSum=0;
        int costSum=0;
        
        for(int i=0;i<n;i++){
            gasSum+=gas[i];
            costSum+=cost[i];
        }
        if(gasSum<costSum)return -1;
        
        int curr=0;
        int start=0;
        
        for(int i=0;i<n;i++){
            curr+=(gas[i]-cost[i]);
            if(curr<0){
                curr=0;
                start=i+1;
            }
        }
        if(curr>=0)return start;
        return -1;
            
        
    }
};