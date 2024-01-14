class Solution {
public:
    bool isPossible(long long int required,vector<int> &candies,long long k,long long int n){
        
        long long int count=0;
        
        for(long long int i=0;i<n;i++){
            
            count+= (candies[i]/required);
        }
        
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long int n= candies.size();
        
        long long int start=1,end=0;
        for(long long int i=0;i<n;i++)end+= candies[i];
        
        int res= (-1);
        while(start<=end){
            
            long long int mid= start + (end-start)/2;
            
            if(isPossible(mid,candies,k,n)){
                
                res=mid;
                start= mid+1;
            }
            else end= mid-1;
        }
        
        return (res== -1?0:res);
    }
};