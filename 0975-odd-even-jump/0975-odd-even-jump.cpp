class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
       int n=arr.size();
        
        vector<int> higher(n),lower(n);
        
        map<int,int>h;
        int res=1;
        
        h[arr[n-1]]=n-1;
        higher[n-1]=lower[n-1]=1;
        
        for(int i=n-2;i>=0;i--){
            // auto val=arr[i];
            auto hi=h.lower_bound(arr[i]);
            auto lo=h.upper_bound(arr[i]);
            
            if(hi != h.end()){
                higher[i]=lower[hi->second];
            }
            if(lo != h.begin()){
                lo--;
                lower[i]=higher[lo->second];
            }
            
            if(higher[i])res++;
            
            h[arr[i]]=i;
        }
        
        return res;
    }
};
