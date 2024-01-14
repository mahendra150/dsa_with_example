class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        
        long long sum=0;
        long long res= 0;
        
        for(int i=0;i<n;i++){
            
            sum+= nums[i];
            double average= (double)(sum)/(i+1);
            long long subRes= ceil(average);
            res=max(res,subRes);
        }
        
        return res;
    }
};