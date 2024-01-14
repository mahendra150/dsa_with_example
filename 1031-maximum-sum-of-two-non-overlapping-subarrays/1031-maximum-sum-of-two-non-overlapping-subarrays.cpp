class Solution {
public:
    
    int utility(vector<int> &nums,int x,int y,int n){
        
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        
        // Forward -->
        
        int prefixSum=0;
        for(int i=0;i<n;i++){
            
            prefixSum+= nums[i];
            if(i>x-1){
                
                prefixSum-=nums[i-x];
                dp1[i]=max(dp1[i-1],prefixSum);
            }
            else dp1[i]= prefixSum;
        }
        
        // <-- Backward
        prefixSum=0;
        for(int i=n-1;i>=0;i--){
            
            prefixSum+= nums[i];
            if(n-i-1>=y){
                
                prefixSum-= nums[i+y];
                dp2[i]=max(dp2[i+1],prefixSum);
            }
            else dp2[i]= prefixSum;
        }
        
        int res= 0;
        for(int i=x-1;i<n-y;i++){
            
            auto possibleAns= dp1[i] + dp2[i+1];
            res=max(res,possibleAns);
        }
        
        return res;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n= nums.size();
        
        return max(utility(nums,firstLen,secondLen,n),utility(nums,secondLen,firstLen,n));
    }
};