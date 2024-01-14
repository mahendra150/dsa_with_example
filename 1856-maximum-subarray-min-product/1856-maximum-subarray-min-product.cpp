class Solution {
public:
    int mod= 1e9+7;
    vector<int> nsr;
    vector<int> nsl;
    
    void nextSmallerToRight(vector<int> &nums,int n){
        
        stack<int> st;
        for(int i=0;i<n;i++){
            
            while(!st.empty() and nums[i]<nums[st.top()]){
                
                nsr[st.top()]= i;
                st.pop();
            }
            
            st.push(i);
        }
        
        
    }
    void nextSmallerToLeft(vector<int> &nums,int n){
        
        stack<int> st;
        for(int i=0;i<n;i++){
            
            while(!st.empty() and nums[i]<nums[st.top()]){
                
                st.pop();
            }
            
            if(!st.empty()) nsl[i]= st.top();
            st.push(i);
        }
        
    }
    int maxSumMinProduct(vector<int>& nums) {
        int n= nums.size();
        
        nsr.resize(n,-1);
        nsl.resize(n,-1);
        
        nextSmallerToLeft(nums,n);
        nextSmallerToRight(nums,n);
        
        vector<long long int> prefixSum;
        long long int sum=0;
        
        for(int i=0;i<n;i++){
            
           sum+= nums[i];
            prefixSum.push_back(sum);
        }
        
        for(int i=0;i<n;i++){
            
            if(nsl[i]==(-1))nsl[i]= (-1);
            if(nsr[i]==(-1))nsr[i]= n;
        }
        
         long long int res= 0;
        for(int i=0;i<n;i++){
            
            auto left= nsl[i]+1;
            auto right= nsr[i]-1;
            
            // if(left==(-1))left=i;
            // if(right==n)right=i;
            long long int maxSum= (left<=0?prefixSum[right]:prefixSum[right]-prefixSum[left-1]);
            // long long int minProduct= nums[i]*maxSum;
            res=max(res,nums[i]*maxSum);
        }
        
        return res%mod;
        
    }
};