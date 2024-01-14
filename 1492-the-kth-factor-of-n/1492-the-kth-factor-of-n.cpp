class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> s;
        
        for(int i=1;i<=sqrt(n);i++){
            
            if(n % i==0){
                s.insert(i);
                
                if(i != sqrt(n)){
                    
                    s.insert(n/i);
                }
            }
        }
        
        if(s.size()<k)return -1;
        
        // while(k>=1){
        //     k--;
        //     cout<<*s.begin()<<endl;
        //     auto address= s.find(*s.begin());
        //     if(address != s.end())s.erase(address);
        // }
        
        int count=1;
        while(1){
            if(count==k){
                return *s.begin();
            }
            else{
                auto address= s.find(*s.begin());
                if(address != s.end())s.erase(address);
            }
            count++;
        }
        
        return -1;
        
    }
};