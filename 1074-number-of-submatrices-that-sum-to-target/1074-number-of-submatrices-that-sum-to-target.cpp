class Solution {
public:
    int subArraySumEqualsK(vector<int> &nums,int k){
        int n= nums.size();
        
        unordered_map<int,int> h;
        int prefixSum=0;
        int res=0;
        
        h[0]+=1;
        for(int i=0;i<n;i++){
            
            prefixSum+= nums[i];
            if(h.count(prefixSum-k))res+= h[prefixSum-k];
            
            h[prefixSum]+=1;
        }
        
        return res;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m= matrix[0].size();
        
        int ans= 0;
        for(int j=0;j<m;j++){
            
            vector<int> prefixSum(n);
            for(int startCol=j;startCol<m;startCol++){
                
                for(int i=0;i<n;i++){
                    
                    prefixSum[i]+= matrix[i][startCol];
                }
                
                auto count= subArraySumEqualsK(prefixSum,target);
                ans+= count;
            }
            
        }
        
        return ans;
        
    }
};