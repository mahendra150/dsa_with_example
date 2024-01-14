class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==2)return {nums[0],nums[1]};
        int x=0,y;
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        
        //ans= x ^ y
        
        int indx;
        for(int i=0;i<32;i++){
            if(ans & (1<<i)){
                indx=i;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(nums[i] & (1<<indx)){
                x^=nums[i];
            }
        }
        
        //ans= x ^ y
        
        y=x^ans;
        
        return {x,y};
    }
};