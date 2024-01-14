class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1,0);
        
        for(int i=0;i<n+1;i++){
            
            int left= max(0,i-ranges[i]);
            int right= min(n,i+ranges[i]);
            
            jumps[left]=max(jumps[left],right-left);
        }
        
        // Greedy Logic of : Jump Game II
        
        int currReach=0;
        int farthest=0;
        int jump=0;
        
        for(int i=0;i<n;i++){
            
            farthest=max(farthest,i+jumps[i]);
            
            if(i==currReach){
                
                jump++;
                currReach=farthest;
            }
        }
        
        if(currReach>=n)return jump;
        
        return (-1);
        
    }
};