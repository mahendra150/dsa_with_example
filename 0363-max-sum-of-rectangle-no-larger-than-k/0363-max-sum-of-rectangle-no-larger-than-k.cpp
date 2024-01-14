class Solution {
public:
    int subArraySumEqualsK(vector<int> &sum,int k){
        int n=sum.size();
        set<int> s;
        
        s.insert(0);
        
        int res= INT_MIN;
        int prefixSum=0;
        for(int i=0;i<n;i++){
            prefixSum+=sum[i];
            
            auto it= s.lower_bound(prefixSum-k);
            if(it != s.end()){                     // ( (prefixSum) - ((prefixSum-k)+lambda) )
                res=max(res,prefixSum - *it);      //  k-lambda
            }
            if(res==k)return k;
            
            s.insert(prefixSum);
        }
        
        return res;
    }
    int maxSumSubArray(vector<int> &sum){
        int n=sum.size();
        
        int prefixSum=0;
        int maxSum= INT_MIN;
        
        for(int i=0;i<n;i++){
            
            prefixSum+=sum[i];
            maxSum=max(maxSum,prefixSum);
            
            if(prefixSum<0)prefixSum=0;
        }
        
        return maxSum;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int m= matrix[0].size();
        
        int res=INT_MIN;
        
        for(int j=0;j<m;j++){
            
                vector<int> sum(n,0);

            for(int startCol=j;startCol<m;startCol++){
                
                for(int i=0;i<n;i++){
                    
                    sum[i]+= matrix[i][startCol];
                }
                
             int currMax=maxSumSubArray(sum);
                
            if(currMax==k)return k;
            
            else if(currMax<k){
                res=max(res,currMax);
            }
            
            else{
                
                currMax= subArraySumEqualsK(sum,k);
                res=max(res,currMax);
            }
                
            }
        }
        
        return res;
        
    }
};