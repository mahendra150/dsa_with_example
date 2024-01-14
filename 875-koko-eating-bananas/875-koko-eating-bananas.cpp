class Solution {
public:
    bool isPossible(vector<int>&piles,int k,int h){
        int n=piles.size();
        
        for(auto p:piles){
            h=h-(p/k + (p%k != 0));
        }
        
        return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(h<n)return -1;
        
        int s=1,e=0,res=(-1);
        
        for(int i=0;i<n;i++)e=max(e,piles[i]);
        
        while(s<=e){
            int mid= s + (e-s)/2;
            if(isPossible(piles,mid,h)){
                res=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        
        return res;
        
        
        
    }
};