class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n= colors.length();
        
        int sumCost=0, maxCost=0;
        int res=0;
        
       for(int i=0;i<n;i++){
           
           if(i>0 and colors[i] != colors[i-1]){
               
               res+= (sumCost-maxCost);
               sumCost=0;
               maxCost=0;
           }
           
           sumCost+= neededTime[i];
           maxCost=max(maxCost,neededTime[i]);
       }
        
        // For last group
        res+= (sumCost-maxCost);
        
        return res;
        
        
    }
};