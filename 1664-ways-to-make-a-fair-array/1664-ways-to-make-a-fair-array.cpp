class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n= nums.size();
        
        int prefixEven=0;
        int prefixOdd=0;
        int suffixEven=0;
        int suffixOdd=0;
        
        for(int i=0;i<n;i++){
            
            if(i&1)prefixOdd+= nums[i];
            else prefixEven+= nums[i];
        }
        
        // I will start removing each index one by one
        //       [prefix][i][suffix]
        
        int count=0;
        for(int i=n-1;i>=0;i--){
            
            if(i % 2 == 0){
                
                prefixEven-= nums[i];
            }
            else prefixOdd-= nums[i];
            
            if(prefixEven + suffixEven == prefixOdd+suffixOdd)count+=1;
            
            if(i % 2 == 0){
                
                suffixOdd+= nums[i];
            }
            else suffixEven+= nums[i];
        }
        
        return count;
    }
};