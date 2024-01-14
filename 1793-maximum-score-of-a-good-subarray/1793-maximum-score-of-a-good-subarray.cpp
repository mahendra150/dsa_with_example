class Solution {
public:
    vector<long long int> nsl;
    vector<long long int> nsr;
    
    void nextSmallerToRight(vector<int> &nums,int n){
        
        stack<long long int> s;
        for(int i=0;i<n;i++){
            
            while(!s.empty() and nums[i]<nums[s.top()]){
                
              nsr[s.top()]=i;
                s.pop();
            }
            
            s.push(i);
        }
        
    }
    void nextSmallerToLeft(vector<int> &nums,int n){
        
        stack<long long int> s;
        for(int i=0;i<n;i++){
            
            while(!s.empty() and nums[i]<nums[s.top()]){
                
                s.pop();
            }
            
            if(!s.empty()) nsl[i]= s.top();
            s.push(i);
        }
        
    }
    int maximumScore(vector<int>& nums, int k) {
        int n= nums.size();
        
        nsl.resize(n,-1);
        nsr.resize(n,-1);
        
        nextSmallerToLeft(nums,n);
        nextSmallerToRight(nums,n);
        
        for(int i=0;i<n;i++){
            
            if(nsl[i]==(-1))nsl[i]=(-1);
            if(nsr[i]==(-1))nsr[i]= n;
        }
        
        long long int maxArea= INT_MIN;
        for(int i=0;i<n;i++){
            
            if(nsl[i]<k and nsr[i]>k){
                
                auto breadth= nsr[i]-nsl[i]-1;
                auto height= nums[i];
                
                maxArea=max(maxArea, height*breadth);
            }
        }
        
        return maxArea;
    }
};