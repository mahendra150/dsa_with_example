class Solution {
public:
    typedef long long ll;
    int countPrimes(int n) {
        
        ll prime[5000005];
        
        for(ll i=0;i<n;i++)prime[i]=1;
        
        prime[0]=0;
        prime[1]=0;
        
        for(ll i=0;i<n;i++){
            if(prime[i]==1){
                for(ll j=i*i;j<n;j+=i)prime[j]=i;
            }
        }
        
        int count=0;
        for(ll i=2;i<n;i++)if(prime[i]==1)count++;
        
        return count;
        
    }
};