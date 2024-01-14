class Solution {
public:
    bool isPossible(int radius,vector<int> &houses,vector<int> &heaters,int n,int m){
        int i=0;
        int j=0;
        
        while(i<n){
            if(j==m)return false;
            
            int left=heaters[j]-radius;
            int right=heaters[j]+radius;
            
            if(houses[i]>=left and houses[i]<=right)i++;
            else if(houses[i]<left or houses[i]>right)j++;
            
        }
        //If I reach the end of houses,return true;
        
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        int m=heaters.size();
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        int start=0;
        int end=1e9;
        int res=0;
        
        while(start<=end){
            int mid= start + (end-start)/2;
            
            if(isPossible(mid,houses,heaters,n,m)){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        
        return res;
        
        
        
    }
};