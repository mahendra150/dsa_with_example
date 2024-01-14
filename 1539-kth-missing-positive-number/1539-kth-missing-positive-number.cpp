class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int start=0,end=n-1;
        
        while(start<=end){
            int mid= start + (end-start)/2;
            
            int numberofMissingElements= arr[mid] - (mid+1);
            
            if(k<=numberofMissingElements){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        
        //Important Derivation for kth missing --> (start+k);
        return (start+k);
        
    }
};