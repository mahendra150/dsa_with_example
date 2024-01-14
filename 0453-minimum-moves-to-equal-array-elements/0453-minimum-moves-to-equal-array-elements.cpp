class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mi=1e9;
        
        for(int i=0;i<n;i++){
            mi=min(mi,nums[i]);
        }
        
        int steps=0;
        for(int i=0;i<n;i++){
            
            steps+= (nums[i]-mi);
        }
        
        return steps;
    }
};